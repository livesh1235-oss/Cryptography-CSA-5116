#include <stdio.h>
#include <stdint.h>

/*
 * 30. CBC MAC Extension / Forgery Property
 * For one-block message X with tag T = MAC(K, X):
 * For message X || (X ^ T):
 * - Block 1 encrypts to T.
 * - Block 2 input = (X ^ T) ^ T = X.
 * - Block 2 encrypts X, yielding T.
 * Adversary produces valid tag for 2-block message without knowing K!
 */

// Simulated block cipher encryption E_K
uint32_t dummy_cipher(uint32_t block, uint32_t key) {
    return (block ^ key) * 0x9E3779B1;
}

uint32_t cbc_mac(const uint32_t *msg, int num_blocks, uint32_t key) {
    uint32_t tag = 0;
    for (int i = 0; i < num_blocks; i++) {
        tag = dummy_cipher(msg[i] ^ tag, key);
    }
    return tag;
}

int main(void) {
    uint32_t key = 0xDEADBEEF;
    uint32_t X = 0x12345678;

    printf("--- 30. CBC MAC One-Block Forgery Demonstration ---\n\n");
    uint32_t T = cbc_mac(&X, 1, key);
    printf("Single-block message X: 0x%08X\n", X);
    printf("Computed Tag T:         0x%08X\n\n", T);

    // Adversary crafts 2-block message: X || (X ^ T)
    uint32_t forged_msg[2];
    forged_msg[0] = X;
    forged_msg[1] = X ^ T;

    printf("Adversary crafts 2-block message:\n");
    printf("  Block 1: 0x%08X\n", forged_msg[0]);
    printf("  Block 2: 0x%08X (X ^ T)\n\n", forged_msg[1]);

    uint32_t forged_tag = cbc_mac(forged_msg, 2, key);
    printf("MAC of crafted 2-block message: 0x%08X\n", forged_tag);
    printf("Does MAC match original T?      %s\n\n", (forged_tag == T) ? "YES (FORGERY CONFIRMED)" : "NO");
    printf("Explanation: In CBC MAC, the first block outputs T, which XORs with\n"
           "the second block (X ^ T) to yield X again. Hence tag = E_K(X) = T.\n");

    return 0;
}
