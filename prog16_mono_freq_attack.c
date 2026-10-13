#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
 * 16. Automated frequency analysis on monoalphabetic substitution cipher.
 * Maps letters by descending frequency against standard English order.
 */

// Letters ordered by standard English frequency
const char *english_order = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

typedef struct {
    char letter;
    int count;
} Freq;

int cmp_freq(const void *a, const void *b) {
    return ((Freq *)b)->count - ((Freq *)a)->count;
}

int main(void) {
    const char *cipher = 
        "GDUC QCIK JGIYDO YI GDUC GZCYM GU OWFFCII. "
        "YERYDO DI GZCYM GU DUOPCYM GDUC JGIYDO.";

    Freq counts[26];
    for (int i = 0; i < 26; i++) {
        counts[i].letter = (char)('A' + i);
        counts[i].count = 0;
    }

    for (int i = 0; cipher[i]; i++) {
        if (isalpha((unsigned char)cipher[i])) {
            counts[toupper((unsigned char)cipher[i]) - 'A'].count++;
        }
    }

    qsort(counts, 26, sizeof(Freq), cmp_freq);

    char map[26];
    for (int i = 0; i < 26; i++) {
        map[counts[i].letter - 'A'] = english_order[i];
    }

    printf("--- 16. Frequency Analysis on Monoalphabetic Substitution ---\n\n");
    printf("Ciphertext:\n%s\n\n", cipher);
    printf("Derived Frequency Mapping (Cipher -> English Guess):\n");
    for (int i = 0; i < 26; i++) {
        if (counts[i].count > 0) {
            printf("%c(%d)->%c  ", counts[i].letter, counts[i].count, english_order[i]);
        }
    }
    printf("\n\nCandidate Plaintext Decryption:\n");
    for (int i = 0; cipher[i]; i++) {
        if (isalpha((unsigned char)cipher[i])) {
            char mapped = map[toupper((unsigned char)cipher[i]) - 'A'];
            putchar(islower((unsigned char)cipher[i]) ? tolower(mapped) : mapped);
        } else {
            putchar(cipher[i]);
        }
    }
    printf("\n");

    return 0;
}
