#include <stdio.h>

/*
 * CO1_AT2 Task 5: Number Theory in Cryptography Implementation
 * Demonstrates:
 * 1. Extended Euclidean Algorithm
 * 2. Modular Inverse
 * 3. Fermat's Little Theorem
 * 4. Euler's Phi Function
 * 5. Euler's Theorem in RSA Cryptosystem
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

long long modInverse(long long a, long long m) {
    long long x, y;
    long long g = extgcd(a, m, &x, &y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}

long long modExp(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main(void) {
    printf("============================================================\n");
    printf("   CO1_AT2: NUMBER THEORY IN CRYPTOGRAPHY DEMONSTRATION     \n");
    printf("============================================================\n\n");

    // 1 & 2: Extended Euclidean Algorithm & Modular Inverse
    long long a = 17, m = 3120;
    long long inv = modInverse(a, m);
    printf("1 & 2. Extended Euclidean Algorithm & Modular Inverse:\n");
    printf("   Finding inverse of a = %lld mod m = %lld\n", a, m);
    printf("   Inverse a^(-1) = %lld (Check: (%lld * %lld) mod %lld = %lld)\n\n",
           inv, a, inv, m, (a * inv) % m);

    // 3. Fermat's Little Theorem
    long long p = 23; // prime
    long long base = 5;
    printf("3. Fermat's Little Theorem (p = %lld is prime, base = %lld):\n", p, base);
    printf("   base^(p-1) mod p = %lld^(%lld) mod %lld = %lld (Guaranteed 1)\n\n",
           base, p - 1, p, modExp(base, p - 1, p));

    // 4. Euler's Phi Function
    long long prime1 = 53, prime2 = 59;
    long long n = prime1 * prime2;
    long long phi = (prime1 - 1) * (prime2 - 1);
    printf("4. Euler's Phi Function:\n");
    printf("   Primes: p = %lld, q = %lld -> Modulus n = %lld\n", prime1, prime2, n);
    printf("   phi(n) = (p - 1)(q - 1) = %lld * %lld = %lld\n\n", prime1 - 1, prime2 - 1, phi);

    // 5. Euler's Theorem & RSA
    long long e = 17;
    long long d = modInverse(e, phi);
    long long M = 1234; // Plaintext message
    long long C = modExp(M, e, n); // Encryption
    long long decM = modExp(C, d, n); // Decryption

    printf("5. Euler's Theorem & RSA Cryptosystem:\n");
    printf("   Public exponent e = %lld\n", e);
    printf("   Private exponent d = %lld (e^(-1) mod phi(n))\n", d);
    printf("   Original Message M  = %lld\n", M);
    printf("   Ciphertext C = M^e mod n = %lld\n", C);
    printf("   Decrypted M = C^d mod n  = %lld (Verification: %s)\n",
           decM, (decM == M) ? "SUCCESS" : "FAIL");

    return 0;
}
