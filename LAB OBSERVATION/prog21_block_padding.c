#include <stdio.h>
#include <string.h>
#include <stdint.h>

/*
 * 21. Block Padding (1-bit followed by zero bits / Byte padding 0x80 ... 0x00)
 * Motivation for including a padding block even when message is a multiple:
 * Unambiguous unpadding! Without this rule, if a valid plaintext naturally ends
 * with the padding byte pattern, the receiver cannot know whether to strip it.
 */

int pad_message(const uint8_t *in, int in_len, int block_size, uint8_t *out) {
    memcpy(out, in, in_len);
    int pad_len = block_size - (in_len % block_size);
    // Standard bit padding: 0x80 (10000000b) followed by 0x00s
    out[in_len] = 0x80;
    for (int i = 1; i < pad_len; i++) {
        out[in_len + i] = 0x00;
    }
    return in_len + pad_len;
}

int unpad_message(const uint8_t *in, int padded_len) {
    int i = padded_len - 1;
    while (i >= 0 && in[i] == 0x00) i--;
    if (i >= 0 && in[i] == 0x80) return i; // original length
    return -1; // invalid padding
}

int main(void) {
    printf("--- 21. Block Padding Scheme & Motivation ---\n\n");
    int block_size = 8; // 64 bits = 8 bytes

    uint8_t msg1[] = "HELLO"; // 5 bytes (needs 3 bytes padding)
    uint8_t padded1[16];
    int len1 = pad_message(msg1, 5, block_size, padded1);

    printf("Case 1: Message length not multiple of block size (5 bytes):\n");
    printf("Padded length: %d bytes (Hex: ", len1);
    for (int i = 0; i < len1; i++) printf("%02X ", padded1[i]);
    printf(")\nUnpadded recovered length: %d\n\n", unpad_message(padded1, len1));

    uint8_t msg2[] = "COMPLETE"; // 8 bytes (exact multiple)
    uint8_t padded2[24];
    int len2 = pad_message(msg2, 8, block_size, padded2);

    printf("Case 2: Message length IS exact multiple of block size (8 bytes):\n");
    printf("Padded length: %d bytes (Full extra padding block added)\nHex: ", len2);
    for (int i = 0; i < len2; i++) printf("%02X ", padded2[i]);
    printf("\nUnpadded recovered length: %d\n\n", unpad_message(padded2, len2));

    printf("Motivation:\n");
    printf("If an extra block were NOT added when a message ends on a block boundary,\n"
           "a message naturally ending in 0x80 0x00 would be erroneously truncated on decryption.\n"
           "Always appending padding guarantees 100%% unambiguous reversal.\n");

    return 0;
}
