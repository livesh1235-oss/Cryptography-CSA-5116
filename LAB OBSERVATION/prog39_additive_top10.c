#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
 * 39. Letter frequency attack on additive cipher (Top 10 plaintexts)
 */

const double eng_freq[26] = {
    8.17, 1.49, 2.78, 4.25, 12.70, 2.23, 2.02, 6.09, 6.97, 0.15,
    0.77, 4.03, 2.41, 6.75, 7.51, 1.93, 0.10, 5.99, 6.33, 9.06,
    2.76, 0.98, 2.36, 0.15, 1.97, 0.07
};

typedef struct { int shift; double score; char text[256]; } Candidate;
int compare(const void *a, const void *b) {
    double diff = ((Candidate*)b)->score - ((Candidate*)a)->score;
    return (diff > 0) ? 1 : ((diff < 0) ? -1 : 0);
}

int main(void) {
    const char *ct = "PHHW PH DIWHU WKH WRJD SDUWB";
    Candidate list[26];

    for (int s = 0; s < 26; s++) {
        list[s].shift = s; list[s].score = 0;
        int len = 0;
        for (int i = 0; ct[i]; i++) {
            if (isalpha((unsigned char)ct[i])) {
                char p = (char)((toupper((unsigned char)ct[i]) - 'A' - s + 26) % 26 + 'A');
                list[s].text[len++] = p;
                list[s].score += eng_freq[p - 'A'];
            } else list[s].text[len++] = ct[i];
        }
        list[s].text[len] = '\0';
    }
    qsort(list, 26, sizeof(Candidate), compare);

    printf("--- 39. Additive Cipher Frequency Attack (Top 10 Plaintexts) ---\n");
    for (int i = 0; i < 10; i++) {
        printf("Rank %2d (Shift %2d, Score %6.2f): %s\n", i+1, list[i].shift, list[i].score, list[i].text);
    }
    return 0;
}
