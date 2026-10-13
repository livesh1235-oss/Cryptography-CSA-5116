#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * 10. Playfair cipher encryption with given matrix:
 * M F H I/J K
 * U N O P   Q
 * Z V W X   Y
 * E L A R   G
 * D S T B   C
 * Message: "Must see you over Cadogan West. Coming at once."
 */

char matrix[5][5] = {
    {'M', 'F', 'H', 'I', 'K'},
    {'U', 'N', 'O', 'P', 'Q'},
    {'Z', 'V', 'W', 'X', 'Y'},
    {'E', 'L', 'A', 'R', 'G'},
    {'D', 'S', 'T', 'B', 'C'}
};

void find_pos(char ch, int *r, int *c) {
    if (ch == 'J') ch = 'I';
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                *r = i; *c = j;
                return;
            }
        }
    }
}

void playfair_encrypt(const char *plain, char *cipher) {
    char clean[512];
    int len = 0;
    for (int i = 0; plain[i] != '\0'; i++) {
        if (isalpha((unsigned char)plain[i])) {
            char ch = (char)toupper((unsigned char)plain[i]);
            if (ch == 'J') ch = 'I';
            clean[len++] = ch;
        }
    }

    char prep[512];
    int p_len = 0;
    for (int i = 0; i < len; i++) {
        prep[p_len++] = clean[i];
        if (i + 1 < len) {
            if (clean[i] == clean[i+1]) {
                prep[p_len++] = 'X';
            } else {
                prep[p_len++] = clean[++i];
            }
        } else {
            prep[p_len++] = 'X';
        }
    }
    prep[p_len] = '\0';

    int out = 0;
    for (int i = 0; i < p_len; i += 2) {
        int r1, c1, r2, c2;
        find_pos(prep[i], &r1, &c1);
        find_pos(prep[i+1], &r2, &c2);

        if (r1 == r2) {
            cipher[out++] = matrix[r1][(c1 + 1) % 5];
            cipher[out++] = matrix[r2][(c2 + 1) % 5];
        } else if (c1 == c2) {
            cipher[out++] = matrix[(r1 + 1) % 5][c1];
            cipher[out++] = matrix[(r2 + 1) % 5][c2];
        } else {
            cipher[out++] = matrix[r1][c2];
            cipher[out++] = matrix[r2][c1];
        }
    }
    cipher[out] = '\0';
}

int main(void) {
    const char *plain = "Must see you over Cadogan West. Coming at once.";
    char cipher[512];

    printf("--- 10. Playfair Encryption (Cadogan West) ---\n");
    printf("Matrix:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    playfair_encrypt(plain, cipher);
    printf("\nPlaintext:  %s\n", plain);
    printf("Ciphertext: ");
    for (int i = 0; cipher[i] != '\0'; i += 2) {
        printf("%c%c ", cipher[i], cipher[i+1]);
    }
    printf("\n");

    return 0;
}
