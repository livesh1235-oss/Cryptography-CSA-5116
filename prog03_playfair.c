#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void generate_matrix(const char *key) {
    int map[26] = {0};
    map['J' - 'A'] = 1; // Treat I and J as same
    int r = 0, c = 0;

    for (int i = 0; key[i] != '\0'; i++) {
        char ch = (char)toupper((unsigned char)key[i]);
        if (!isalpha((unsigned char)ch)) continue;
        if (ch == 'J') ch = 'I';
        if (!map[ch - 'A']) {
            matrix[r][c] = ch;
            map[ch - 'A'] = 1;
            c++;
            if (c == 5) { c = 0; r++; }
        }
    }

    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (ch == 'J') continue;
        if (!map[ch - 'A']) {
            matrix[r][c] = ch;
            map[ch - 'A'] = 1;
            c++;
            if (c == 5) { c = 0; r++; }
        }
    }
}

void find_pos(char ch, int *r, int *c) {
    if (ch == 'J') ch = 'I';
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                *r = i;
                *c = j;
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

    char prepared[512];
    int p_len = 0;
    for (int i = 0; i < len; i++) {
        prepared[p_len++] = clean[i];
        if (i + 1 < len) {
            if (clean[i] == clean[i + 1]) {
                prepared[p_len++] = 'X';
            } else {
                prepared[p_len++] = clean[++i];
            }
        } else {
            prepared[p_len++] = 'X';
        }
    }
    prepared[p_len] = '\0';

    int out = 0;
    for (int i = 0; i < p_len; i += 2) {
        int r1, c1, r2, c2;
        find_pos(prepared[i], &r1, &c1);
        find_pos(prepared[i + 1], &r2, &c2);

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
    char key[100] = "MONARCHY";
    char plain[256] = "INSTRUMENTS";
    char cipher[512];

    printf("--- 3. Playfair Cipher ---\n");
    printf("Key: %s\n", key);
    generate_matrix(key);
    printf("5x5 Matrix:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    playfair_encrypt(plain, cipher);
    printf("Plaintext:  %s\n", plain);
    printf("Ciphertext: %s\n", cipher);

    return 0;
}
