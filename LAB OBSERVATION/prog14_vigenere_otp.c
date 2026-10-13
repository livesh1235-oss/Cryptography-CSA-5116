#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * 14. One-Time Pad / Vigenere Stream Cipher
 * a. Encrypt "send more money" with key stream:
 *    9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9
 * b. Find key so that resulting ciphertext decrypts to "cash not needed"
 */

int main(void) {
    const char *p1_raw = "send more money";
    int k1[] = {9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    char p1[64];
    int len1 = 0;

    for (int i = 0; p1_raw[i]; i++) {
        if (isalpha((unsigned char)p1_raw[i])) {
            p1[len1++] = (char)tolower((unsigned char)p1_raw[i]);
        }
    }
    p1[len1] = '\0';

    printf("--- 14. One-Time Pad Version of Vigenere ---\n\n");
    printf("Part (a):\n");
    printf("Plaintext 1: %s\n", p1);
    printf("Key stream:  ");
    for (int i = 0; i < len1; i++) printf("%d ", k1[i]);
    printf("\n");

    char c1[64];
    for (int i = 0; i < len1; i++) {
        int shift = k1[i];
        c1[i] = (char)(((p1[i] - 'a' + shift) % 26) + 'A');
    }
    c1[len1] = '\0';
    printf("Ciphertext:  %s\n\n", c1);

    printf("Part (b):\n");
    const char *p2_raw = "cash not needed";
    char p2[64];
    int len2 = 0;
    for (int i = 0; p2_raw[i]; i++) {
        if (isalpha((unsigned char)p2_raw[i])) {
            p2[len2++] = (char)tolower((unsigned char)p2_raw[i]);
        }
    }
    p2[len2] = '\0';
    printf("Target Plaintext 2: %s\n", p2);

    int k2[64];
    for (int i = 0; i < len2; i++) {
        // C[i] - K2[i] = P2[i]  =>  K2[i] = C[i] - P2[i] (mod 26)
        k2[i] = ((c1[i] - 'A') - (p2[i] - 'a') + 26) % 26;
    }
    printf("Derived Key Stream: ");
    for (int i = 0; i < len2; i++) printf("%d ", k2[i]);
    printf("\n");

    // Verification
    printf("Decryption check with new key:\n");
    for (int i = 0; i < len2; i++) {
        char ch = (char)((((c1[i] - 'A') - k2[i] + 26) % 26) + 'a');
        printf("%c", ch);
    }
    printf("\n");

    return 0;
}
