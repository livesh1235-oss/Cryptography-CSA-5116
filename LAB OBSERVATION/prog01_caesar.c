#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caesar_encrypt(char *text, int k) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isupper((unsigned char)text[i])) {
            text[i] = (char)(((text[i] - 'A' + k) % 26) + 'A');
        } else if (islower((unsigned char)text[i])) {
            text[i] = (char)(((text[i] - 'a' + k) % 26) + 'a');
        }
    }
}

void caesar_decrypt(char *text, int k) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isupper((unsigned char)text[i])) {
            text[i] = (char)(((text[i] - 'A' - k + 26) % 26) + 'A');
        } else if (islower((unsigned char)text[i])) {
            text[i] = (char)(((text[i] - 'a' - k + 26) % 26) + 'a');
        }
    }
}

int main(void) {
    char text[256];
    int k;

    printf("--- 1. Caesar Cipher ---\n");
    printf("Enter plaintext: ");
    if (!fgets(text, sizeof(text), stdin)) return 0;
    text[strcspn(text, "\r\n")] = '\0';

    printf("Enter shift key k (1-25): ");
    if (scanf("%d", &k) != 1 || k < 1 || k > 25) {
        printf("Invalid key. Setting default k = 3.\n");
        k = 3;
    }

    caesar_encrypt(text, k);
    printf("Encrypted Ciphertext: %s\n", text);

    caesar_decrypt(text, k);
    printf("Decrypted Plaintext:  %s\n", text);

    return 0;
}
