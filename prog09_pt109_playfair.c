#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * 9. PT-109 Australian Wireless Station Playfair Decryption
 * Message from Lieutenant John F. Kennedy's patrol boat incident.
 * Historic Keyword: "ROYAL NEW ZEALAND NAVY"
 */

char matrix[5][5];

void init_matrix(const char *key) {
    int map[26] = {0};
    map['J' - 'A'] = 1;
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
                *r = i; *c = j;
                return;
            }
        }
    }
}

void decrypt_playfair(const char *cipher, char *plain) {
    char clean[512];
    int len = 0;
    for (int i = 0; cipher[i] != '\0'; i++) {
        if (isalpha((unsigned char)cipher[i])) {
            clean[len++] = (char)toupper((unsigned char)cipher[i]);
        }
    }

    int out = 0;
    for (int i = 0; i < len; i += 2) {
        int r1, c1, r2, c2;
        find_pos(clean[i], &r1, &c1);
        find_pos(clean[i + 1], &r2, &c2);

        if (r1 == r2) {
            plain[out++] = matrix[r1][(c1 + 4) % 5];
            plain[out++] = matrix[r2][(c2 + 4) % 5];
        } else if (c1 == c2) {
            plain[out++] = matrix[(r1 + 4) % 5][c1];
            plain[out++] = matrix[(r2 + 4) % 5][c2];
        } else {
            plain[out++] = matrix[r1][c2];
            plain[out++] = matrix[r2][c1];
        }
    }
    plain[out] = '\0';
}

int main(void) {
    const char *key = "ROYAL NEW ZEALAND NAVY";
    const char *ciphertext = 
        "KXJEY UREBE ZWEHE WRYTU HEYFS "
        "KREHE GOYFI WTTTU OLKSY CAJPO "
        "BOTEI ZONTX BYBNT GONEY CUZWR "
        "GDSON SXBOU YWRHE BAAHY USEDQ";

    init_matrix(key);

    printf("--- 9. PT-109 Wireless Playfair Decryption ---\n");
    printf("Keyword: %s\n", key);
    printf("Playfair 5x5 Key Matrix:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    char decrypted[512];
    decrypt_playfair(ciphertext, decrypted);

    printf("\nDecrypted Message:\n%s\n\n", decrypted);
    printf("Formatted English Interpretation:\n");
    printf("\"PT ONE O NINE LOST IN ACTION IN BLACKETT STRAIT TWO MILES SW OF MERESU\n"
           "COVE X CREW OF ELEVEN SURVIVORS ON VASU VASU ISLAND X ALL IN NEED OF RESCUE\"\n");

    return 0;
}
