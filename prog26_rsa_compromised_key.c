#include <stdio.h>

/*
 * 26. RSA Compromised Private Key Re-use
 * If Bob leaks his private key d, generating new (e', d') with the SAME n is UNSAFE.
 * Knowing (e, d, n) allows full factorization of n into p and q.
 */

int main(void) {
    printf("--- 26. RSA Compromised Key Modulus Reuse ---\n\n");
    printf("Question: If Bob leaks private key d, is it safe to pick new (e', d') with the same n?\n");
    printf("Answer: NO, IT IS COMPLETELY INSECURE.\n\n");

    printf("Explanation:\n");
    printf("1. Once (e, d) is known for modulus n, the product (e*d - 1) is a multiple of phi(n).\n");
    printf("2. A standard probabilistic algorithm can factor n = p*q in polynomial time\n");
    printf("   using (e*d - 1).\n");
    printf("3. Anyone who recorded the old leaked key can instantly factor n, compute the new phi(n),\n");
    printf("   and derive Bob's new private key d' from his new public key e'.\n");
    printf("4. Rule: Once a private key is leaked, a FRESH modulus n (new p and q) MUST be generated.\n");

    return 0;
}
