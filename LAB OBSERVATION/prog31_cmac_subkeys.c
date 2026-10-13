#include <stdio.h>
#include <stdint.h>

/*
 * 31. CMAC Subkey Generation (RFC 4493)
 * a. Constants:
 *    - For 64-bit block size:  Rb = 0x1B
 *    - For 128-bit block size: Rb = 0x87
 * b. Left shift and XOR explanation:
 *    Represents multiplication by x in GF(2^b). Left shift multiplies by x;
 *    if the MSB was 1, modular reduction by the irreducible polynomial is
 *    achieved by XORing with Rb.
 */

// 64-bit CMAC subkey derivation
void derive_cmac_keys_64(uint64_t L, uint64_t *K1, uint64_t *K2) {
    uint64_t const_Rb = 0x1BULL;

    // Derive K1
    if ((L & 0x8000000000000000ULL) == 0) {
        *K1 = L << 1;
    } else {
        *K1 = (L << 1) ^ const_Rb;
    }

    // Derive K2
    if ((*K1 & 0x8000000000000000ULL) == 0) {
        *K2 = *K1 << 1;
    } else {
        *K2 = (*K1 << 1) ^ const_Rb;
    }
}

int main(void) {
    printf("--- 31. CMAC Subkey Generation Analysis & Derivation ---\n\n");
    printf("a. Reduction Polynomial Constants:\n");
    printf("   - 64-bit block size:  Rb = 0x1B (x^64 + x^4 + x^3 + x + 1)\n");
    printf("   - 128-bit block size: Rb = 0x87 (x^128 + x^7 + x^2 + x + 1)\n\n");

    printf("b. Mathematical Explanation:\n");
    printf("   - Multiplication by x in GF(2^n) equals a bitwise shift left by 1.\n");
    printf("   - If the MSB before shift was 1, degree-n overflow occurs.\n");
    printf("   - In Galois field arithmetic, modular reduction modulo the primitive\n");
    printf("     polynomial is performed by XORing with the constant Rb.\n\n");

    // Demonstration with sample 64-bit L = E_K(0)
    uint64_t L = 0x8000000000000001ULL;
    uint64_t K1, K2;
    derive_cmac_keys_64(L, &K1, &K2);

    printf("Example Derivation (64-bit):\n");
    printf("  L  = 0x%016llX\n", (unsigned long long)L);
    printf("  K1 = 0x%016llX\n", (unsigned long long)K1);
    printf("  K2 = 0x%016llX\n", (unsigned long long)K2);

    return 0;
}
