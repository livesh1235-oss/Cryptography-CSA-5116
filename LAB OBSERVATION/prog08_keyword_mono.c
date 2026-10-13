#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * 8. Monoalphabetic substitution cipher generated using a keyword.
 * Keyword CIPHER followed by unused letters in normal alphabetical order.
 */

void generate_cipher_alphabet(const char *keyword, char *cipher_alpha) {
    int used[26] = {0};
    int idx = 0;

    for (int i = 0; keyword[i] != '\0'; i++) {
        char ch = (char)toupper((unsigned char)keyword[i]);
        if (isalpha((unsigned char)ch) && !used[ch - 'A']) {
            cipher_alpha[idx++] = ch;
            used[ch - 'A'] = 1;
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            cipher_alpha[idx++] = ch;
            used[ch - 'A'] = 1;
        }
    }
    cipher_alpha[26] = '\0';
}

void encrypt(const char *plain, const char *cipher_alpha, char *cipher) {
    for (int i = 0; plain[i] != '\0'; i++) {
        if (isalpha((unsigned char)plain[i])) {
            char base = isupper((unsigned char)plain[i]) ? 'A' : 'a';
            char mapped = cipher_alpha[plain[i] - base];
            cipher[i] = isupper((unsigned char)plain[i]) ? mapped : (char)tolower((unsigned char)mapped);
        } else {
            cipher[i] = plain[i];
        }
    }
    cipher[strlen(plain)] = '\0';
}

int main(void) {
    const char *keyword = "CIPHER";
    char cipher_alpha[27];
    generate_cipher_alphabet(keyword, cipher_alpha);

    printf("--- 8. Keyword Monoalphabetic Cipher ---\n");
    printf("Keyword: %s\n", keyword);
    printf("Plain:  abcdefghijklmnopqrstuvwxyz\n");
    printf("Cipher: %s\n\n", cipher_alpha);

    char message[] = "Defend the east wall with archers";
    char encrypted[256];
    encrypt(message, cipher_alpha, encrypted);

    printf("Plaintext:  %s\n", message);
    printf("Ciphertext: %s\n", encrypted);

    return 0;
}
