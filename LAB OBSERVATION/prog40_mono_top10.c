#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
 * 40. Monoalphabetic substitution frequency cryptanalysis
 */

const char *eng = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
typedef struct { char c; int cnt; } Freq;
int cmp(const void *a, const void *b) { return ((Freq*)b)->cnt - ((Freq*)a)->cnt; }

int main(void) {
    const char *cipher = "WKLV LV D WHVW PHVVDJH IRU IUHTXHQFB DQDOBVLV";
    Freq f[26];
    for (int i = 0; i < 26; i++) { f[i].c = 'A' + i; f[i].cnt = 0; }
    for (int i = 0; cipher[i]; i++) {
        if (isalpha((unsigned char)cipher[i])) f[toupper((unsigned char)cipher[i]) - 'A'].cnt++;
    }
    qsort(f, 26, sizeof(Freq), cmp);

    char map[26];
    for (int i = 0; i < 26; i++) map[f[i].c - 'A'] = eng[i];

    printf("--- 40. Monoalphabetic Substitution Frequency Analysis ---\n");
    printf("Ciphertext: %s\nDecrypted:  ", cipher);
    for (int i = 0; cipher[i]; i++) {
        if (isalpha((unsigned char)cipher[i])) putchar(map[toupper((unsigned char)cipher[i]) - 'A']);
        else putchar(cipher[i]);
    }
    printf("\n");
    return 0;
}
