#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * Scenario 2: Intercepted Suspicious Message
 * Intercepted text: "GSRH RH Z HVXIVG"
 * Method: Atbash reciprocal substitution cipher:
 * P <-> 'Z' - (C - 'A') = 25 - C
 */

void atbash_decode(const char *in, char *out) {
    for (int i = 0; in[i]; i++) {
        if (isupper((unsigned char)in[i])) {
            out[i] = (char)('Z' - (in[i] - 'A'));
        } else {
            out[i] = in[i];
        }
    }
    out[strlen(in)] = '\0';
}

int main(void) {
    const char *intercepted = "GSRH RH Z HVXIVG";
    char decoded[64];

    atbash_decode(intercepted, decoded);

    printf("--- Question 2: Intercepted Suspicious Message ---\n");
    printf("Intercepted Ciphertext: %s\n", intercepted);
    printf("Deductions:\n");
    printf("  'Z' is a single-letter word -> Decodes to 'A'\n");
    printf("  'RH' is a two-letter word   -> Decodes to 'IS'\n");
    printf("  'GSRH'                      -> Decodes to 'THIS'\n");
    printf("  'HVXIVG'                    -> Decodes to 'SECRET'\n\n");
    printf("Decoded Original Message: %s\n", decoded);

    return 0;
}
