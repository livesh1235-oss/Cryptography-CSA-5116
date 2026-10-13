#include <stdio.h>

/*
 * 25. RSA Common Factor Vulnerability
 * If a plaintext block M shares a factor with n (i.e. gcd(M, n) > 1),
 * Eve can compute gcd(M, n) which immediately reveals p or q!
 */

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b; b = a % b; a = t;
    }
    return a;
}

int main(void) {
    long long n = 3599; // p = 59, q = 61
    long long e = 31;
    // Suppose a plaintext block M is a multiple of p = 59
    long long M = 118; // 2 * 59

    printf("--- 25. RSA Common Factor Property ---\n\n");
    printf("RSA Modulus n = %lld\n", n);
    printf("Plaintext block M = %lld\n", M);

    long long factor = gcd(M, n);
    printf("Computing gcd(M, n) = %lld\n\n", factor);

    if (factor > 1 && factor < n) {
        long long p = factor;
        long long q = n / p;
        long long phi = (p - 1) * (q - 1);
        printf("FACTORIZATION SUCCESSFUL!\n");
        printf("  Prime p = %lld\n", p);
        printf("  Prime q = %lld\n", q);
        printf("  phi(n)  = %lld\n", phi);
        printf("Does this help? YES! The modulus n is completely factored,\n"
               "allowing immediate calculation of the private key d.\n");
    } else {
        printf("gcd(M, n) = 1 (coprime).\n");
    }

    return 0;
}
