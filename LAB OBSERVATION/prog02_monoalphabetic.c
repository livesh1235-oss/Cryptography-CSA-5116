#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Monoalphabetic substitution cipher */
void encrypt_mono(const char *plain, char *cipher, const char *key) {
    for (int i = 0; plain[i] != '\0'; i++) {
        if (isupper((unsigned char)plain[i])) {
            cipher[i] = (char)toupper((unsigned char)key[plain[i] - 'A']);
        } else if (islower((unsigned char)plain[i])) {
            cipher[i] = (char)tolower((unsigned char)key[plain[i] - 'a']);
        } else {
            cipher[i] = plain[i];
        }
    }
    cipher[strlen(plain)] = '\0';
}

void decrypt_mono(const char *cipher, char *plain, const char *key) {
    char rev_key[26];
    for (int i = 0; i < 26; i++) {
        rev_key[toupper((unsigned char)key[i]) - 'A'] = (char)('A' + i);
    }
    for (int i = 0; cipher[i] != '\0'; i++) {
        if (isupper((unsigned char)cipher[i])) {
            plain[i] = rev_key[cipher[i] - 'A'];
        } else if (islower((unsigned char)cipher[i])) {
            plain[i] = (char)tolower((unsigned char)rev_key[cipher[i] - 'a']);
        } else {
            plain[i] = cipher[i];
        }
    }
    plain[strlen(cipher)] = '\0';
}

int main(void) {
    char plain[256], cipher[256], decrypted[256];
    /* Default substitution key mapping a..z */
    char key[27] = "QWERTYUIOPASDFGHJKLZXCVBNM";

    printf("--- 2. Monoalphabetic Substitution Cipher ---\n");
    printf("Using cipher alphabet: %s\n", key);
    printf("Enter plaintext: ");
    if (!fgets(plain, sizeof(plain), stdin)) return 0;
    plain[strcspn(plain, "\r\n")] = '\0';

    encrypt_mono(plain, cipher, key);
    printf("Ciphertext: %s\n", cipher);

    decrypt_mono(cipher, decrypted, key);
    printf("Decrypted:  %s\n", decrypted);

    return 0;
}
