#include <stdio.h>
#include <stdlib.h>

/*
 * 32. DSA Random Per-Message Nonce k vs RSA Deterministic Signatures
 * - DSA signatures: (r, s) where r = (g^k mod p) mod q.
 *   Even for identical messages, different random k produces different signatures.
 * - RSA signatures: S = m^d mod n is deterministic.
 */

int main(void) {
    printf("--- 32. DSA Nonce vs RSA Deterministic Signatures ---\n\n");

    printf("1. Observation:\n");
    printf("   In DSA, every signature generates a fresh, ephemeral secret number k.\n");
    printf("   Therefore, signing the identical message twice produces two distinct signatures (r1, s1) != (r2, s2).\n");
    printf("   In basic RSA, signature S = m^d mod n produces the exact same signature every time.\n\n");

    printf("2. Security Implications:\n");
    printf("   a. Unlinkability:\n");
    printf("      DSA signatures cannot be trivially matched across transmissions to detect\n");
    printf("      duplicate messages.\n");
    printf("   b. Catastrophic Nonce Reuse Vulnerability in DSA:\n");
    printf("      If the random nonce k is ever repeated for two different messages:\n");
    printf("        s1 - s2 = k^(-1) * (H(m1) - H(m2)) mod q\n");
    printf("      An attacker immediately computes k, and from k recovers the signer's\n");
    printf("      private key x! (Famously broken in Sony PlayStation 3 firmware).\n");
    printf("   c. Deterministic RSA requires no random generator during signing, but requires\n");
    printf("      probabilistic padding (PSS) to resist chosen-ciphertext forgery.\n");

    return 0;
}
