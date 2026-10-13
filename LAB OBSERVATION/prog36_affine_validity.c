#include <stdio.h>

/*
 * 36. Affine Caesar Cipher Analysis: C = (ap + b) mod 26
 * Determine valid and invalid values of a and b.
 */

int gcd(int a, int b) {
    while (b) { int t = b; b = a % b; a = t; }
    return a;
}

int main(void) {
    printf("--- 36. Affine Caesar Cipher Validity Analysis ---\n\n");
    printf("Encryption function: C = (a*p + b) mod 26\n\n");

    printf("a. Limitations on b:\n");
    printf("   b can be any integer in [0, 25]. There are no coprimality restrictions on b.\n\n");

    printf("b. Disallowed values of a:\n");
    printf("   For the function to be one-to-one (bijective), 'a' must be coprime to 26 (gcd(a, 26) == 1).\n");
    printf("   Disallowed values of 'a' (not allowed):\n   ");
    for (int a = 0; a < 26; a++) {
        if (gcd(a, 26) != 1) {
            printf("%d ", a);
        }
    }
    printf("\n   (Namely: 0, 2, 4, 6, 8, 10, 12, 13, 14, 16, 18, 20, 22, 24)\n");

    return 0;
}
