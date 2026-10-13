#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * 35. One-time pad version of Vigenere cipher
 * Encrypt "send more money" with key stream: 9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9
 * Find key to decrypt to "cash not needed"
 */

int main(void) {
    const char *p1 = "sendmoremoney";
    int k1[] = {9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    int len = strlen(p1);

    printf("--- 35. One-Time Pad / Vigenere Stream Cipher ---\n\n");
    char c1[64];
    for (int i = 0; i < len; i++) {
        c1[i] = (char)(((p1[i] - 'a' + k1[i]) % 26) + 'A');
    }
    c1[len] = '\0';
    printf("Plaintext 1: %s\n", p1);
    printf("Ciphertext:  %s\n\n", c1);

    const char *p2 = "cashnotneeded";
    int k2[64];
    for (int i = 0; i < len; i++) {
        k2[i] = ((c1[i] - 'A') - (p2[i] - 'a') + 26) % 26;
    }

    printf("Plaintext 2: %s\n", p2);
    printf("Derived Key: ");
    for (int i = 0; i < len; i++) printf("%d ", k2[i]);
    printf("\n");

    return 0;
}
