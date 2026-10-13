#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenere_encrypt(const char *plain, const char *key, char *cipher) {
    int key_len = strlen(key);
    int j = 0;
    for (int i = 0; plain[i] != '\0'; i++) {
        if (isupper((unsigned char)plain[i])) {
            int shift = toupper((unsigned char)key[j % key_len]) - 'A';
            cipher[i] = (char)(((plain[i] - 'A' + shift) % 26) + 'A');
            j++;
        } else if (islower((unsigned char)plain[i])) {
            int shift = toupper((unsigned char)key[j % key_len]) - 'A';
            cipher[i] = (char)(((plain[i] - 'a' + shift) % 26) + 'a');
            j++;
        } else {
            cipher[i] = plain[i];
        }
    }
    cipher[strlen(plain)] = '\0';
}

void vigenere_decrypt(const char *cipher, const char *key, char *plain) {
    int key_len = strlen(key);
    int j = 0;
    for (int i = 0; cipher[i] != '\0'; i++) {
        if (isupper((unsigned char)cipher[i])) {
            int shift = toupper((unsigned char)key[j % key_len]) - 'A';
            plain[i] = (char)(((cipher[i] - 'A' - shift + 26) % 26) + 'A');
            j++;
        } else if (islower((unsigned char)cipher[i])) {
            int shift = toupper((unsigned char)key[j % key_len]) - 'A';
            plain[i] = (char)(((cipher[i] - 'a' - shift + 26) % 26) + 'a');
            j++;
        } else {
            plain[i] = cipher[i];
        }
    }
    plain[strlen(cipher)] = '\0';
}

int main(void) {
    char plain[256], key[100], cipher[256], decrypted[256];

    printf("--- 4. Polyalphabetic (Vigenere) Cipher ---\n");
    printf("Enter plaintext: ");
    if (!fgets(plain, sizeof(plain), stdin)) return 0;
    plain[strcspn(plain, "\r\n")] = '\0';

    printf("Enter keyword: ");
    if (!fgets(key, sizeof(key), stdin)) return 0;
    key[strcspn(key, "\r\n")] = '\0';

    vigenere_encrypt(plain, key, cipher);
    printf("Ciphertext: %s\n", cipher);

    vigenere_decrypt(cipher, key, decrypted);
    printf("Decrypted:  %s\n", decrypted);

    return 0;
}
