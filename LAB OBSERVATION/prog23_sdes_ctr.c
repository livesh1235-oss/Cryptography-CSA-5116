#include <stdio.h>
#include <stdint.h>

/*
 * 23. Simplified DES (S-DES) in Counter (CTR) Mode
 * Counter starts at 0000 0000 (0x00).
 * Key: 01111 11101 (0x1FD)
 * Plaintext:  0000 0001 0000 0010 0000 0100 (0x01, 0x02, 0x04)
 * Expected:   0011 1000 0100 1111 0011 0010 (0x38, 0x4F, 0x32)
 */

uint8_t s0[4][4] = {{1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 1, 3}, {3, 1, 3, 2}};
uint8_t s1[4][4] = {{0, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 0}, {2, 1, 0, 3}};

void sdes_key_schedule(uint16_t key, uint8_t *k1, uint8_t *k2) {
    int p10[10] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
    uint16_t pk = 0;
    for (int i = 0; i < 10; i++) {
        if (key & (1 << (10 - p10[i]))) pk |= (1 << (9 - i));
    }
    uint8_t left = (pk >> 5) & 0x1F, right = pk & 0x1F;
    left = ((left << 1) | (left >> 4)) & 0x1F;
    right = ((right << 1) | (right >> 4)) & 0x1F;

    int p8[8] = {6, 3, 7, 4, 8, 5, 10, 9};
    uint16_t comb1 = (left << 5) | right;
    *k1 = 0;
    for (int i = 0; i < 8; i++) {
        if (comb1 & (1 << (10 - p8[i]))) *k1 |= (1 << (7 - i));
    }
    left = ((left << 2) | (left >> 3)) & 0x1F;
    right = ((right << 2) | (right >> 3)) & 0x1F;
    uint16_t comb2 = (left << 5) | right;
    *k2 = 0;
    for (int i = 0; i < 8; i++) {
        if (comb2 & (1 << (10 - p8[i]))) *k2 |= (1 << (7 - i));
    }
}

uint8_t fk(uint8_t nibble, uint8_t key) {
    int ep[8] = {4, 1, 2, 3, 2, 3, 4, 1};
    uint8_t expanded = 0;
    for (int i = 0; i < 8; i++) {
        if (nibble & (1 << (4 - ep[i]))) expanded |= (1 << (7 - i));
    }
    expanded ^= key;
    uint8_t l = (expanded >> 4) & 0x0F, r = expanded & 0x0F;
    uint8_t out0 = s0[((l & 8) >> 2) | (l & 1)][(l >> 1) & 3];
    uint8_t out1 = s1[((r & 8) >> 2) | (r & 1)][(r >> 1) & 3];
    uint8_t combined = (out0 << 2) | out1;
    int p4[4] = {2, 4, 3, 1};
    uint8_t res = 0;
    for (int i = 0; i < 4; i++) {
        if (combined & (1 << (4 - p4[i]))) res |= (1 << (3 - i));
    }
    return res;
}

uint8_t sdes_encrypt_byte(uint8_t pt, uint8_t k1, uint8_t k2) {
    int ip[8] = {2, 6, 3, 1, 4, 8, 5, 7};
    uint8_t val = 0;
    for (int i = 0; i < 8; i++) {
        if (pt & (1 << (8 - ip[i]))) val |= (1 << (7 - i));
    }
    uint8_t left = (val >> 4) & 0x0F, right = val & 0x0F;
    left ^= fk(right, k1);
    uint8_t temp = left; left = right; right = temp;
    left ^= fk(right, k2);
    uint8_t comb = (left << 4) | right;
    int ip_inv[8] = {4, 1, 3, 5, 7, 2, 8, 6};
    uint8_t ct = 0;
    for (int i = 0; i < 8; i++) {
        if (comb & (1 << (8 - ip_inv[i]))) ct |= (1 << (7 - i));
    }
    return ct;
}

void print_bin(uint8_t v) {
    for (int i = 7; i >= 0; i--) printf("%d", (v >> i) & 1);
}

int main(void) {
    uint16_t key = 0x1FD; // 01111 11101
    uint8_t k1, k2;
    sdes_key_schedule(key, &k1, &k2);

    uint8_t pt[3] = {0x01, 0x02, 0x04};
    uint8_t ct[3], decrypted[3];
    uint8_t ctr = 0x00;

    printf("--- 23. S-DES Counter (CTR) Mode ---\n\n");
    printf("Starting Counter: 00000000\n");
    printf("Key:              0111111101\n");
    printf("Plaintext:        ");
    for (int i = 0; i < 3; i++) { print_bin(pt[i]); printf(" "); }
    printf("\n\n");

    // CTR Encryption
    for (int i = 0; i < 3; i++) {
        uint8_t stream = sdes_encrypt_byte((uint8_t)(ctr + i), k1, k2);
        ct[i] = pt[i] ^ stream;
    }

    printf("Ciphertext:       ");
    for (int i = 0; i < 3; i++) { print_bin(ct[i]); printf(" "); }
    printf("\n(Expected:        00111000 01001111 00110010)\n\n");

    // CTR Decryption
    for (int i = 0; i < 3; i++) {
        uint8_t stream = sdes_encrypt_byte((uint8_t)(ctr + i), k1, k2);
        decrypted[i] = ct[i] ^ stream;
    }

    printf("Decrypted:        ");
    for (int i = 0; i < 3; i++) { print_bin(decrypted[i]); printf(" "); }
    printf("\n");

    return 0;
}
