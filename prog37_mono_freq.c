#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
 * 37. Frequency analysis attack on monoalphabetic substitution cipher
 */

const char *eng = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

typedef struct { char c; int cnt; } Freq;
int cmp(const void *a, const void *b) { return ((Freq*)b)->cnt - ((Freq*)a)->cnt; }

int main(void) {
    const char *text = "WKLV LV D WHVW PHVVDJH IRU IUHTXHQFB DQDOBVLV";
    Freq f[26];
    for (int i = 0; i < 26; i++) { f[i].c = 'A' + i; f[i].cnt = 0; }
    for (int i = 0; text[i]; i++) {
        if (isalpha((unsigned char)text[i])) f[toupper((unsigned char)text[i]) - 'A'].cnt++;
    }
    qsort(f, 26, sizeof(Freq), cmp);

    char map[26];
    for (int i = 0; i < 26; i++) map[f[i].c - 'A'] = eng[i];

    printf("--- 37. Monoalphabetic Substitution Frequency Attack ---\n");
    printf("Ciphertext: %s\nDecrypted:  ", text);
    for (int i = 0; text[i]; i++) {
        if (isalpha((unsigned char)text[i])) putchar(map[toupper((unsigned char)text[i]) - 'A']);
        else putchar(text[i]);
    }
    printf("\n");
    return 0;
}
