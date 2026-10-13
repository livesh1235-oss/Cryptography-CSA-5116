#include <stdio.h>
#include <string.h>
#include <stdint.h>

/*
 * 34. Padding in ECB, CBC, and CFB modes.
 * Motivation for including a full padding block when padding is not needed.
 */

int main(void) {
    printf("--- 34. Motivation for Padding Blocks in Block Ciphers ---\n\n");
    printf("Question: Why is a padding block appended even when the plaintext is an exact multiple of the block size?\n\n");
    printf("Explanation:\n");
    printf("1. Unambiguous Parsing (Reversibility):\n");
    printf("   If the receiver sees a message, how does it know whether the final bytes are padding or real data?\n");
    printf("   - Case without mandatory padding: If a file naturally ends with 0x80 or 0x01 bytes,\n"
           "     the receiver would mistake valid plaintext for padding and corrupt the file upon stripping it.\n");
    printf("   - With mandatory padding rule: The sender ALWAYS pads every message.\n"
           "     Therefore, the receiver ALWAYS strips the padding indicated by the final bytes.\n"
           "     There is zero ambiguity.\n\n");
    printf("2. Example (PKCS#7 on 8-byte block):\n");
    printf("   - 5 bytes of data -> 3 bytes of padding (05 05 05)\n");
    printf("   - 8 bytes of data -> 8 bytes of padding (08 08 08 08 08 08 08 08 in a new block)\n");
    printf("   This protocol invariant guarantees that decryption unpadding never destroys authentic message data.\n");

    return 0;
}
