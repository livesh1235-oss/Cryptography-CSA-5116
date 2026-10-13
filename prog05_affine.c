#include <stdio.h>
#include <string.h>
#include <ctype.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int modInverse(int a, int m) {
    a = (a % m + m) % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1;
}

void affine_encrypt(const char *plain, char *cipher, int a, int b) {
    for (int i = 0; plain[i] != '\0'; i++) {
        if (isupper((unsigned char)plain[i])) {
            cipher[i] = (char)((((a * (plain[i] - 'A')) + b) % 26) + 'A');
        } else if (islower((unsigned char)plain[i])) {
            cipher[i] = (char)((((a * (plain[i] - 'a')) + b) % 26) + 'a');
        } else {
            cipher[i] = plain[i];
        }
    }
    cipher[strlen(plain)] = '\0';
}

void affine_decrypt(const char *cipher, char *plain, int a, int b) {
    int a_inv = modInverse(a, 26);
    if (a_inv == -1) {
        strcpy(plain, "Decryption impossible: 'a' has no modular inverse.");
        return;
    }
    for (int i = 0; cipher[i] != '\0'; i++) {
        if (isupper((unsigned char)cipher[i])) {
            int p = (a_inv * (cipher[i] - 'A' - b + 260)) % 26;
            plain[i] = (char)(p + 'A');
        } else if (islower((unsigned char)cipher[i])) {
            int p = (a_inv * (cipher[i] - 'a' - b + 260)) % 26;
            plain[i] = (char)(p + 'a');
        } else {
            plain[i] = cipher[i];
        }
    }
    plain[strlen(cipher)] = '\0';
}

int main(void) {
    printf("--- 5. Affine Caesar Cipher Analysis & Implementation ---\n\n");
    printf("a. Limitations on b:\n");
    printf("   b can be any integer in 0..25 (b mod 26). It simply shifts the alphabet.\n");
    printf("   There are NO restrictions on b (no requirement to be coprime with 26).\n\n");

    printf("b. Disallowed values of 'a' (must have gcd(a, 26) == 1):\n");
    printf("   Allowed 'a' values: ");
    for (int a = 0; a < 26; a++) {
        if (gcd(a, 26) == 1) printf("%d ", a);
    }
    printf("\n   Disallowed 'a' values (not coprime with 26): ");
    for (int a = 0; a < 26; a++) {
        if (gcd(a, 26) != 1) printf("%d ", a);
    }
    printf("\n   (Disallowed: even numbers 0,2,4,6,8,10,12,14,16,18,20,22,24 and 13)\n\n");

    char text[100] = "AFFINE CIPHER";
    char cipher[100], decrypted[100];
    int a = 7, b = 2; // Valid: gcd(7, 26) = 1

    printf("Example with valid key (a = %d, b = %d):\n", a, b);
    printf("Plaintext:  %s\n", text);
    affine_encrypt(text, cipher, a, b);
    printf("Ciphertext: %s\n", cipher);
    affine_decrypt(cipher, decrypted, a, b);
    printf("Decrypted:  %s\n", decrypted);

    return 0;
}
