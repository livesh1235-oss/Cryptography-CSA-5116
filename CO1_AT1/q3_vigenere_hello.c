#include <stdio.h>
#include <string.h>

/*
 * Scenario 3: Secure Messaging System
 * Message: "HELLO", Keyword: "KEY"
 */

int main(void) {
    const char *plain = "HELLO";
    const char *key = "KEY";
    int p_len = strlen(plain);
    int k_len = strlen(key);

    printf("--- Question 3: Keyword-based Vigenere Encryption ---\n\n");
    printf("Step-by-step Transformation:\n");
    printf("Idx | Plain | Value | Key | Value | (P + K) mod 26 | Cipher\n");
    printf("-----------------------------------------------------------\n");

    char cipher[64];
    for (int i = 0; i < p_len; i++) {
        int p_val = plain[i] - 'A';
        int k_val = key[i % k_len] - 'A';
        int c_val = (p_val + k_val) % 26;
        cipher[i] = (char)(c_val + 'A');
        printf("%3d | %5c | %5d | %3c | %5d |       %2d       | %6c\n",
               i + 1, plain[i], p_val, key[i % k_len], k_val, c_val, cipher[i]);
    }
    cipher[p_len] = '\0';

    printf("\nFinal Ciphertext: %s\n\n", cipher);
    printf("Influence of repeating keyword:\n");
    printf("- The first 'L' (index 3) is shifted by 'Y' (24) -> 'J'\n");
    printf("- The second 'L' (index 4) is shifted by 'K' (10) -> 'V'\n");
    printf("- Identical plaintext letters produce different ciphertext letters,\n"
           "  effectively concealing frequency patterns.\n");

    return 0;
}
