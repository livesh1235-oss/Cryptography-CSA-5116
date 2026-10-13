#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
 * 15. Letter frequency attack on additive (Caesar) cipher.
 * Outputs top 10 plaintexts ranked by likelihood (unigram English scores).
 */

// Standard English letter frequencies (%)
const double eng_freq[26] = {
    8.17, 1.49, 2.78, 4.25, 12.70, 2.23, 2.02, 6.09, 6.97, 0.15,
    0.77, 4.03, 2.41, 6.75, 7.51, 1.93, 0.10, 5.99, 6.33, 9.06,
    2.76, 0.98, 2.36, 0.15, 1.97, 0.07
};

typedef struct {
    int shift;
    double score;
    char text[256];
} Candidate;

int compare(const void *a, const void *b) {
    Candidate *ca = (Candidate *)a;
    Candidate *cb = (Candidate *)b;
    if (cb->score > ca->score) return 1;
    if (cb->score < ca->score) return -1;
    return 0;
}

int main(void) {
    const char *ciphertext = "KHOOR ZRUOG WKLV LV DQ DGGLWLYH FLSKHU WHVW";
    Candidate list[26];

    printf("--- 15. Letter Frequency Analysis on Additive Cipher ---\n");
    printf("Ciphertext: %s\n\n", ciphertext);

    for (int shift = 0; shift < 26; shift++) {
        list[shift].shift = shift;
        list[shift].score = 0.0;
        int len = 0;
        for (int i = 0; ciphertext[i]; i++) {
            if (isalpha((unsigned char)ciphertext[i])) {
                char base = isupper((unsigned char)ciphertext[i]) ? 'A' : 'a';
                char p = (char)((ciphertext[i] - base - shift + 26) % 26 + base);
                list[shift].text[len++] = p;
                list[shift].score += eng_freq[toupper((unsigned char)p) - 'A'];
            } else {
                list[shift].text[len++] = ciphertext[i];
            }
        }
        list[shift].text[len] = '\0';
    }

    qsort(list, 26, sizeof(Candidate), compare);

    printf("Top 10 Most Likely Plaintexts:\n");
    printf("Rank | Shift | Score   | Plaintext\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < 10; i++) {
        printf("%4d | %5d | %7.2f | %s\n", i + 1, list[i].shift, list[i].score, list[i].text);
    }

    return 0;
}
