#include <stdio.h>
#include <string.h>
#include <ctype.h>

int modInverse(int a, int m) {
    a = (a % m + m) % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1;
}

int main(void) {
    printf("--- 6. Affine Cipher Cryptanalysis ---\n");
    printf("Assumptions based on standard English frequencies:\n");
    printf("Most frequent plaintext letter: E (p1 = 4)\n");
    printf("Second most frequent letter:    T (p2 = 19)\n");
    printf("Given Ciphertext frequencies:\n");
    printf("Most frequent ciphertext letter:   B (c1 = 1)\n");
    printf("Second most frequent letter:       U (c2 = 20)\n\n");

    int p1 = 4, c1 = 1;
    int p2 = 19, c2 = 20;

    int diff_p = (p2 - p1 + 26) % 26; // 15
    int diff_c = (c2 - c1 + 26) % 26; // 19

    int inv_p = modInverse(diff_p, 26);
    if (inv_p == -1) {
        printf("Error: diff_p (%d) has no inverse mod 26.\n", diff_p);
        return 1;
    }

    int a = (diff_c * inv_p) % 26;
    int b = (c1 - a * p1) % 26;
    if (b < 0) b += 26;

    printf("Equations:\n");
    printf("  (a * 4  + b) = 1  (mod 26)\n");
    printf("  (a * 19 + b) = 20 (mod 26)\n\n");
    printf("Solution found:\n");
    printf("  Multiplier key 'a' = %d\n", a);
    printf("  Shift key      'b' = %d\n", b);

    int a_inv = modInverse(a, 26);
    printf("  Decryption key a^(-1) = %d\n", a_inv);
    printf("  Decryption equation: p = %d * (C - %d) mod 26\n\n", a_inv, b);

    // Demonstration decryption on sample text
    char sample_cipher[] = "BUB";
    printf("Decrypting test ciphertext \"%s\":\n", sample_cipher);
    for (int i = 0; sample_cipher[i] != '\0'; i++) {
        int c = sample_cipher[i] - 'A';
        int p = (a_inv * (c - b + 260)) % 26;
        printf("%c -> %c\n", sample_cipher[i], (char)(p + 'A'));
    }

    return 0;
}
