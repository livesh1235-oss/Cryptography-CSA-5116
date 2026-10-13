#include <stdio.h>

/*
 * 28. Diffie-Hellman Protocol Analysis
 * What if participants sent x^a mod q instead of a^x mod q?
 * In x^a mod q, Eve can easily find secret x by computing the modular a-th root!
 */

long long gcd(long long a, long long b) {
    while (b) { long long t = b; b = a % b; a = t; }
    return a;
}

long long modInverse(long long a, long long m) {
    for (long long x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1;
}

int main(void) {
    printf("--- 28. Diffie-Hellman Variant Analysis ---\n\n");
    printf("Standard DH: Participants send Y = a^x mod q (Discrete Logarithm Problem - HARD).\n");
    printf("Variant:     Participants send Y = x^a mod q (Modular Root Problem - EASY).\n\n");

    printf("Can Eve break the variant system?\n");
    printf("YES! If gcd(a, q - 1) = 1, then 'a' has a modular inverse modulo (q - 1):\n");
    printf("  d = a^(-1) mod (q - 1)\n");
    printf("Then Eve simply computes:\n");
    printf("  Y^d mod q = (x^a)^d mod q = x^(a*d) mod q = x mod q\n\n");
    printf("Eve instantly recovers the secret number x in polynomial time!\n");
    printf("Therefore, this variant is insecure and fails to protect the secret keys.\n");

    return 0;
}
