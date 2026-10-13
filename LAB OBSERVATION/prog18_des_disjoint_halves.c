#include <stdio.h>
#include <stdint.h>

/*
 * 18. DES Subkey Bit Independence:
 * Shows that the first 24 bits of each subkey come exclusively from C (first 28 bits)
 * and the second 24 bits come exclusively from D (second 28 bits).
 */

// PC-2 permutation table (1-indexed, values 1-28 are from C, 29-56 are from D)
const int pc2[48] = {
    14, 17, 11, 24,  1,  5,  3, 28, 15,  6, 21, 10,
    23, 19, 12,  4, 26,  8, 16,  7, 27, 20, 13,  2,
    41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32
};

int main(void) {
    printf("--- 18. DES Subkey Disjoint 24-Bit Analysis ---\n\n");
    int first_half_from_C = 1;
    int second_half_from_D = 1;

    printf("Analyzing PC-2 bit selection:\n");
    printf("Bits 1 to 24 of Subkey (First Half):\n  ");
    for (int i = 0; i < 24; i++) {
        printf("%d ", pc2[i]);
        if (pc2[i] > 28) first_half_from_C = 0;
    }
    printf("\n  All <= 28 (Derived from C)? %s\n\n", first_half_from_C ? "YES (All from C)" : "NO");

    printf("Bits 25 to 48 of Subkey (Second Half):\n  ");
    for (int i = 24; i < 48; i++) {
        printf("%d ", pc2[i]);
        if (pc2[i] <= 28) second_half_from_D = 0;
    }
    printf("\n  All > 28 (Derived from D)? %s\n\n", second_half_from_D ? "YES (All from D)" : "NO");

    printf("Conclusion: The first 24 bits and second 24 bits of each round subkey\n"
           "are strictly drawn from disjoint 28-bit subsets (C and D) of the 56-bit key.\n");

    return 0;
}
