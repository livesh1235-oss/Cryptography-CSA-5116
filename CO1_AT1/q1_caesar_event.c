#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * Scenario 1: Event Communication Security
 * Message: "MEET AT NOON"
 * Shift: k = 4
 */

void caesar_encrypt(const char *in, char *out, int k) {
    for (int i = 0; in[i]; i++) {
        if (isupper((unsigned char)in[i])) {
            out[i] = (char)(((in[i] - 'A' + k) % 26) + 'A');
        } else {
            out[i] = in[i];
        }
    }
    out[strlen(in)] = '\0';
}

void caesar_decrypt(const char *in, char *out, int k) {
    for (int i = 0; in[i]; i++) {
        if (isupper((unsigned char)in[i])) {
            out[i] = (char)(((in[i] - 'A' - k + 26) % 26) + 'A');
        } else {
            out[i] = in[i];
        }
    }
    out[strlen(in)] = '\0';
}

int main(void) {
    const char *msg = "MEET AT NOON";
    char ct[64], pt[64];
    int k = 4;

    printf("--- Question 1: Event Communication Security ---\n");
    printf("Original Plaintext: %s\n", msg);
    printf("Shift applied (k):  %d\n", k);

    caesar_encrypt(msg, ct, k);
    printf("Encrypted Ciphertext: %s\n", ct);

    caesar_decrypt(ct, pt, k);
    printf("Retrieved Plaintext:  %s\n", pt);

    return 0;
}
