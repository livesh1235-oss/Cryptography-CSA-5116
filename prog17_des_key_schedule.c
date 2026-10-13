#include <stdio.h>

/*
 * 17. DES Decryption Key Schedule
 * In DES decryption, the 16 subkeys (K1..K16) are applied in reverse order.
 * Demonstrates the shift schedule and round key ordering for decryption.
 */

// Round shifts for standard DES encryption
const int des_shifts[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

int main(void) {
    printf("--- 17. DES Decryption Key Schedule ---\n\n");
    printf("Standard DES Encryption Shift Schedule:\n");
    printf("Round: ");
    for (int i = 0; i < 16; i++) printf("%2d ", i + 1);
    printf("\nShift: ");
    for (int i = 0; i < 16; i++) printf("%2d ", des_shifts[i]);
    printf("\n\n");

    printf("Decryption Key Application Order:\n");
    printf("Decryption Round | Subkey Applied | Encryption Round Equivalent\n");
    printf("----------------------------------------------------------------\n");
    for (int r = 1; r <= 16; r++) {
        printf("%16d | K%02d           | Round %d\n", r, 17 - r, 17 - r);
    }

    printf("\nKey property:\n");
    printf("Because Feistel decryption is mathematically identical to encryption\n");
    printf("with reversed round subkeys, DES decryption requires no new algorithm,\n");
    printf("only reversing the order of subkeys from K16 down to K1.\n");

    return 0;
}
