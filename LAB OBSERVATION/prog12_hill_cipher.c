#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * 12. Hill Cipher (2x2 Matrix)
 * Key:
 * [9 4]
 * [5 7]
 * Plaintext: "meet me at the usual place at ten rather than eight oclock"
 */

int mod26(int x) {
    int r = x % 26;
    return (r < 0) ? r + 26 : r;
}

int modInverse(int a, int m) {
    a = mod26(a);
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1;
}

int main(void) {
    int K[2][2] = {{9, 4}, {5, 7}};
    int det = mod26(K[0][0] * K[1][1] - K[0][1] * K[1][0]);
    int det_inv = modInverse(det, 26);

    printf("--- 12. Hill Cipher 2x2 Encryption & Decryption ---\n\n");
    printf("Encryption Key K:\n [%2d %2d]\n [%2d %2d]\n", K[0][0], K[0][1], K[1][0], K[1][1]);
    printf("Determinant: %d = %d (mod 26)\n", (9*7 - 4*5), det);
    printf("det^(-1) mod 26: %d\n\n", det_inv);

    // Decryption matrix: det_inv * adj(K) mod 26
    // adj(K) = [K[1][1], -K[0][1]; -K[1][0], K[0][0]] = [7, -4; -5, 9]
    int K_inv[2][2];
    K_inv[0][0] = mod26( K[1][1] * det_inv);
    K_inv[0][1] = mod26(-K[0][1] * det_inv);
    K_inv[1][0] = mod26(-K[1][0] * det_inv);
    K_inv[1][1] = mod26( K[0][0] * det_inv);

    printf("Decryption Key K^(-1):\n [%2d %2d]\n [%2d %2d]\n\n", 
           K_inv[0][0], K_inv[0][1], K_inv[1][0], K_inv[1][1]);

    const char *raw = "meet me at the usual place at ten rather than eight oclock";
    char text[256];
    int len = 0;
    for (int i = 0; raw[i]; i++) {
        if (isalpha((unsigned char)raw[i])) {
            text[len++] = (char)tolower((unsigned char)raw[i]);
        }
    }
    if (len % 2 != 0) text[len++] = 'x';
    text[len] = '\0';

    char cipher[256], decrypted[256];
    for (int i = 0; i < len; i += 2) {
        int p0 = text[i] - 'a';
        int p1 = text[i+1] - 'a';
        cipher[i]   = (char)(mod26(K[0][0] * p0 + K[0][1] * p1) + 'A');
        cipher[i+1] = (char)(mod26(K[1][0] * p0 + K[1][1] * p1) + 'A');
    }
    cipher[len] = '\0';

    for (int i = 0; i < len; i += 2) {
        int c0 = cipher[i] - 'A';
        int c1 = cipher[i+1] - 'A';
        decrypted[i]   = (char)(mod26(K_inv[0][0] * c0 + K_inv[0][1] * c1) + 'a');
        decrypted[i+1] = (char)(mod26(K_inv[1][0] * c0 + K_inv[1][1] * c1) + 'a');
    }
    decrypted[len] = '\0';

    printf("Plaintext:  %s\n", text);
    printf("Ciphertext: %s\n", cipher);
    printf("Decrypted:  %s\n", decrypted);

    return 0;
}
