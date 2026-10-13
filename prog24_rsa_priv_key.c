#include <stdio.h>
#include <math.h>

/*
 * 24. RSA Private Key Calculation
 * Public key: e = 31, n = 3599.
 * 1. Factor n by trial division around sqrt(3599) -> p = 59, q = 61.
 * 2. phi(n) = (p-1)*(q-1) = 58 * 60 = 3480.
 * 3. Extended Euclidean algorithm: find d = e^(-1) mod phi(n).
 */

long long extgcd(long long a, long long b, long long *x, long long *y) {
    if (b == 0) {
        *x = 1; *y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = extgcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}

int main(void) {
    long long n = 3599;
    long long e = 31;
    long long p = 0, q = 0;

    printf("--- 24. RSA Private Key Derivation ---\n\n");
    printf("Given Public Key: e = %lld, n = %lld\n", e, n);

    // Step 1: Trial division around sqrt(3599)
    long long limit = (long long)sqrt(n) + 1;
    for (long long i = limit; i >= 2; i--) {
        if (n % i == 0) {
            p = i;
            q = n / i;
            break;
        }
    }

    printf("Step 1: Factoring n:\n");
    printf("  sqrt(%lld) ≈ %.2f\n", n, sqrt(n));
    printf("  Found primes: p = %lld, q = %lld (check: %lld * %lld = %lld)\n\n", p, q, p, q, p * q);

    // Step 2: phi(n)
    long long phi = (p - 1) * (q - 1);
    printf("Step 2: Totient phi(n):\n");
    printf("  phi(%lld) = (%lld - 1) * (%lld - 1) = %lld * %lld = %lld\n\n", n, p, q, p - 1, q - 1, phi);

    // Step 3: Extended Euclidean Algorithm
    long long x, y;
    extgcd(e, phi, &x, &y);
    long long d = (x % phi + phi) % phi;

    printf("Step 3: Multiplicative inverse of %lld mod %lld:\n", e, phi);
    printf("  Private key d = %lld\n", d);
    printf("  Verification: (e * d) mod phi = (%lld * %lld) mod %lld = %lld\n\n",
           e, d, phi, (e * d) % phi);

    printf("Result: Bob's private key is d = %lld.\n", d);
    return 0;
}
