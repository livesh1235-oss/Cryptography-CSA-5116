#include <stdio.h>

/*
 * 27. RSA Small Message Space / Character Encryption Vulnerability
 * Alice encrypts letters individually: 0 to 25.
 * Eve precomputes C_i = (i^e) mod n for all 26 letters and breaks it instantly.
 */

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
    long long e = 31, n = 3599;

    printf("--- 27. RSA Single-Character Dictionary Vulnerability ---\n\n");
    printf("Parameters: e = %lld, n = %lld\n", e, n);

    // Eve's precomputed lookup table
    long long dict[26];
    for (int i = 0; i < 26; i++) {
        dict[i] = modExp(i, e, n);
    }

    printf("Precomputed Dictionary for A-Z (0-25):\n");
    for (int i = 0; i < 5; i++) {
        printf("  '%c' (%2d) -> Cipher: %4lld\n", 'A' + i, i, dict[i]);
    }
    printf("  ... (all 26 values easily precomputed)\n\n");

    // Alice transmits ciphertext for "HELLO"
    const char *secret = "HELLO";
    long long cipher[5];
    printf("Intercepted Ciphertext for Alice's secret message:\n  ");
    for (int i = 0; secret[i]; i++) {
        cipher[i] = modExp(secret[i] - 'A', e, n);
        printf("%lld ", cipher[i]);
    }
    printf("\n\n");

    // Eve decrypts by table lookup
    printf("Eve decodes via table lookup without private key:\n  Decoded: ");
    for (int i = 0; i < 5; i++) {
        for (int m = 0; m < 26; m++) {
            if (cipher[i] == dict[m]) {
                printf("%c", 'A' + m);
                break;
            }
        }
    }
    printf("\n\nConclusion: Encrypting small deterministic alphabetic tokens individually\n"
           "is completely broken by precomputed codebook attack. RSA must use randomized padding (OAEP).\n");

    return 0;
}
