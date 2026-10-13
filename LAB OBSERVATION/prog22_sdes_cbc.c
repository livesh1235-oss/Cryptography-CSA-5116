#include <stdio.h>
#include <stdint.h>

/*
 * 22. Simplified DES (S-DES) in CBC Mode
 * Test Data:
 *   Binary IV:        1010 1010 (0xAA)
 *   Binary Plaintext: 0000 0001 0010 0011 (0x01, 0x23)
 *   Binary Key:       01111 11101 (0x1FD)
 *   Expected Cipher:  1111 0100 0000 1011 (0xF4, 0x0B)
 */

uint8_t s0[4][4] = {
    {1, 0, 3, 2},
    {3, 2, 1, 0},
    {0, 2, 1, 3},
    {3, 1, 3, 2}
};

uint8_t s1[4][4] = {
    {0, 1, 2, 3},
    {2, 0, 1, 3},
    {3, 0, 1, 0},
    {2, 1, 0, 3}
};

void sdes_key_schedule(uint16_t key, uint8_t *k1, uint8_t *k2) {
    // P10: 3, 5, 2, 7, 4, 10, 1, 9, 8, 6
    int p10[10] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
    uint16_t pk = 0;
    for (int i = 0; i < 10; i++) {
        if (key & (1 << (10 - p10[i]))) pk |= (1 << (9 - i));
    }
    uint8_t left = (pk >> 5) & 0x1F;
    uint8_t right = pk & 0x1F;

    // LS-1
    left = ((left << 1) | (left >> 4)) & 0x1F;
    right = ((right << 1) | (right >> 4)) & 0x1F;

    // P8 for K1: 6, 3, 7, 4, 8, 5, 10, 9
    int p8[8] = {6, 3, 7, 4, 8, 5, 10, 9};
    uint16_t comb1 = (left << 5) | right;
    *k1 = 0;
    for (int i = 0; i < 8; i++) {
        if (comb1 & (1 << (10 - p8[i]))) *k1 |= (1 << (7 - i));
    }

    // LS-2
    left = ((left << 2) | (left >> 3)) & 0x1F;
    right = ((right << 2) | (right >> 3)) & 0x1F;

    uint16_t comb2 = (left << 5) | right;
    *k2 = 0;
    for (int i = 0; i < 8; i++) {
        if (comb2 & (1 << (10 - p8[i]))) *k2 |= (1 << (7 - i));
    }
}

uint8_t fk(uint8_t nibble, uint8_t key) {
    // EP: 4, 1, 2, 3, 2, 3, 4, 1
    int ep[8] = {4, 1, 2, 3, 2, 3, 4, 1};
    uint8_t expanded = 0;
    for (int i = 0; i < 8; i++) {
        if (nibble & (1 << (4 - ep[i]))) expanded |= (1 << (7 - i));
    }
    expanded ^= key;
    uint8_t l = (expanded >> 4) & 0x0F;
    uint8_t r = expanded & 0x0F;

    int row0 = ((l & 0x8) >> 2) | (l & 0x1);
    int col0 = (l >> 1) & 0x3;
    uint8_t out0 = s0[row0][col0];

    int row1 = ((r & 0x8) >> 2) | (r & 0x1);
    int col1 = (r >> 1) & 0x3;
    uint8_t out1 = s1[row1][col1];

    uint8_t combined = (out0 << 2) | out1;
    // P4: 2, 4, 3, 1
    int p4[4] = {2, 4, 3, 1};
    uint8_t res = 0;
    for (int i = 0; i < 4; i++) {
        if (combined & (1 << (4 - p4[i]))) res |= (1 << (3 - i));
    }
    return res;
}

uint8_t sdes_encrypt_byte(uint8_t pt, uint8_t k1, uint8_t k2) {
    // IP: 2, 6, 3, 1, 4, 8, 5, 7
    int ip[8] = {2, 6, 3, 1, 4, 8, 5, 7};
    uint8_t val = 0;
    for (int i = 0; i < 8; i++) {
        if (pt & (1 << (8 - ip[i]))) val |= (1 << (7 - i));
    }
    uint8_t left = (val >> 4) & 0x0F;
    uint8_t right = val & 0x0F;

    left ^= fk(right, k1);
    // Swap
    uint8_t temp = left; left = right; right = temp;

    left ^= fk(right, k2);

    uint8_t comb = (left << 4) | right;
    // IP^-1: 4, 1, 3, 5, 7, 2, 8, 6
    int ip_inv[8] = {4, 1, 3, 5, 7, 2, 8, 6};
    uint8_t ct = 0;
    for (int i = 0; i < 8; i++) {
        if (comb & (1 << (8 - ip_inv[i]))) ct |= (1 << (7 - i));
    }
    return ct;
}

uint8_t sdes_decrypt_byte(uint8_t ct, uint8_t k1, uint8_t k2) {
    return sdes_encrypt_byte(ct, k2, k1);
}

void print_bin(uint8_t v) {
    for (int i = 7; i >= 0; i--) printf("%d", (v >> i) & 1);
}

int main(void) {
    uint16_t key = 0x1FD; // 01111 11101
    uint8_t iv = 0xAA;    // 1010 1010
    uint8_t pt[2] = {0x01, 0x23}; // 00000001, 00100011
    uint8_t ct[2], decrypted[2];

    uint8_t k1, k2;
    sdes_key_schedule(key, &k1, &k2);

    printf("--- 22. S-DES CBC Mode Encryption & Decryption ---\n\n");
    printf("Input Data:\n");
    printf("IV:        "); print_bin(iv); printf("\n");
    printf("Key:       0111111101\n");
    printf("Plaintext: "); print_bin(pt[0]); printf(" "); print_bin(pt[1]); printf("\n\n");

    // CBC Encryption
    uint8_t prev = iv;
    for (int i = 0; i < 2; i++) {
        ct[i] = sdes_encrypt_byte(pt[i] ^ prev, k1, k2);
        prev = ct[i];
    }

    printf("Ciphertext: "); print_bin(ct[0]); printf(" "); print_bin(ct[1]);
    printf(" (Expected: 11110100 00001011)\n");

    // CBC Decryption
    prev = iv;
    for (int i = 0; i < 2; i++) {
        decrypted[i] = sdes_decrypt_byte(ct[i], k1, k2) ^ prev;
        prev = ct[i];
    }

    printf("Decrypted:  "); print_bin(decrypted[0]); printf(" "); print_bin(decrypted[1]);
    printf(" (Matched: %s)\n", (decrypted[0] == pt[0] && decrypted[1] == pt[1]) ? "YES" : "NO");

    return 0;
}
