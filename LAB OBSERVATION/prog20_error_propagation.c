#include <stdio.h>
#include <stdint.h>

/*
 * 20. Error Propagation Analysis: ECB vs CBC Mode
 * - In ECB mode: 1 bit error in ciphertext affects only that single block.
 * - In CBC mode: 1 bit error in C1 corrupts entire P1 and bit-errors P2.
 */

int main(void) {
    printf("--- 20. Error Propagation: ECB vs CBC Mode ---\n\n");

    printf("a. Does an error in C1 affect blocks beyond P2 in CBC mode?\n");
    printf("   Answer: NO.\n");
    printf("   In CBC: P[i] = D_K(C[i]) ^ C[i-1].\n");
    printf("   - P1 depends on C1 and IV (corrupted completely).\n");
    printf("   - P2 depends on C2 and C1 (bit error in C1 flips identical bit in P2).\n");
    printf("   - P3 depends on C3 and C2 (completely unaffected).\n");
    printf("   Therefore, errors in C1 do NOT propagate beyond P2 (CBC is self-synchronizing).\n\n");

    printf("b. If there is a bit error in source plaintext P1:\n");
    printf("   - Plaintext error in P1 corrupts C1.\n");
    printf("   - Because C1 is corrupted, it propagates through ALL subsequent ciphertext blocks\n"
           "     C1, C2, C3, ... to the end of transmission.\n");
    printf("   - At receiver, decryption recovers corrupted P1, but if ciphertext wasn't corrupted\n"
           "     in transit, P2, P3... decrypt to their original transmitted values.\n");

    return 0;
}
