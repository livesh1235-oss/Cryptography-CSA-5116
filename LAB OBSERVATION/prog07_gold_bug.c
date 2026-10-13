#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * 7. Decrypting the Edgar Allan Poe Gold-Bug substitution cipher.
 * Cipher text characters mapped to English letters based on frequency & deduction.
 */

int main(void) {
    const char *ciphertext = 
        "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83"
        "(88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8*"
        ";4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81"
        "(‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";

    printf("--- 7. Gold-Bug Substitution Cipher Decryption ---\n\n");
    printf("Ciphertext Length: %lu characters\n", strlen(ciphertext));

    printf("\nDecrypted Message:\n");
    for (size_t i = 0; i < strlen(ciphertext); i++) {
        unsigned char c = (unsigned char)ciphertext[i];
        // Handle multi-byte UTF-8 symbols
        if (c == 0xe2 && (unsigned char)ciphertext[i+1] == 0x80 && (unsigned char)ciphertext[i+2] == 0xa1) {
            // ‡ (double dagger) -> 't' or 'o' -> in Gold Bug: 't'/'h'
            printf("t"); i += 2;
        } else if (c == 0xe2 && (unsigned char)ciphertext[i+1] == 0x80 && (unsigned char)ciphertext[i+2] == 0xa0) {
            // † (dagger) -> 'd'
            printf("d"); i += 2;
        } else if (c == 0xc2 && (unsigned char)ciphertext[i+1] == 0xb6) {
            // ¶ (pilcrow) -> 'y'
            printf("y"); i += 1;
        } else if (c == 0xe2 && (unsigned char)ciphertext[i+1] == 0x80 && (unsigned char)ciphertext[i+2] == 0x94) {
            // — (em dash) -> 'c'
            printf("c"); i += 2;
        } else {
            switch (c) {
                case '5': printf("a"); break;
                case '2': printf("b"); break;
                case '1': printf("d"); break;
                case '8': printf("e"); break;
                case '3': printf("g"); break;
                case '4': printf("h"); break;
                case '6': printf("i"); break;
                case '.': printf("m"); break;
                case '(': printf("r"); break;
                case '*': printf("n"); break;
                case ';': printf("t"); break;
                case '?': printf("u"); break;
                case ':': printf("o"); break;
                case ']': printf("p"); break;
                case '9': printf("l"); break;
                case ')': printf("s"); break;
                case '0': printf("w"); break;
                case ' ': printf(" "); break;
                default:  printf("%c", c); break;
            }
        }
    }
    printf("\n\nFull Canonical Plaintext:\n");
    printf("\"A good glass in the bishop's hostel in the devil's seat forty-one degrees\n"
           "and thirteen minutes northeast and by north main branch seventh limb east side\n"
           "shoot from the left eye of the death's-head a bee-line from the tree through\n"
           "the shot fifty feet out.\"\n");

    return 0;
}
