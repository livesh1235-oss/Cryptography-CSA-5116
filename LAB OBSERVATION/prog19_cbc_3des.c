#include <stdio.h>
#include <stdint.h>

/*
 * 19. CBC Mode with 3DES Simulation
 * Demonstrates 3DES (EDE: Encrypt-Decrypt-Encrypt) with CBC chaining.
 * Compares security and performance trade-offs.
 */

// Simple block function simulating 3DES
uint64_t dummy_des_encrypt(uint64_t block, uint64_t k) { return block ^ k; }
uint64_t dummy_des_decrypt(uint64_t block, uint64_t k) { return block ^ k; }

uint64_t triple_des_encrypt(uint64_t block, uint64_t k1, uint64_t k2, uint64_t k3) {
    uint64_t s1 = dummy_des_encrypt(block, k1);
    uint64_t s2 = dummy_des_decrypt(s1, k2);
    return dummy_des_encrypt(s2, k3);
}

int main(void) {
    printf("--- 19. 3DES in CBC Mode & Trade-off Analysis ---\n\n");
    uint64_t iv = 0xA1B2C3D4E5F60718ULL;
    uint64_t k1 = 0x1111222233334444ULL;
    uint64_t k2 = 0x5555666677778888ULL;
    uint64_t k3 = 0x9999AAAABBBBCCCCULL;

    uint64_t plaintext[2] = {0x0123456789ABCDEFULL, 0xFEDCBA9876543210ULL};
    uint64_t ciphertext[2];

    uint64_t prev = iv;
    for (int i = 0; i < 2; i++) {
        uint64_t xor_input = plaintext[i] ^ prev;
        ciphertext[i] = triple_des_encrypt(xor_input, k1, k2, k3);
        prev = ciphertext[i];
    }

    printf("IV:             0x%016llX\n", (unsigned long long)iv);
    printf("Ciphertext C1:  0x%016llX\n", (unsigned long long)ciphertext[0]);
    printf("Ciphertext C2:  0x%016llX\n\n", (unsigned long long)ciphertext[1]);

    printf("Analysis Comparison:\n");
    printf("a. Security: 3DES is vastly superior to single DES (112 or 168-bit effective key)\n"
           "   protecting against brute-force attacks on 56-bit DES.\n");
    printf("b. Performance: Single DES is ~3x faster; 3DES performs 3 Feistel operations per block.\n");

    return 0;
}
