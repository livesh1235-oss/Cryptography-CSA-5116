#include <stdio.h>

/*
 * 29. SHA-3 (Keccak) Capacity State Absorption
 * Total state = 1600 bits = 25 lanes (each 64 bits) arranged in a 5x5 matrix.
 * Block size (rate r) = 1024 bits = 16 lanes.
 * Capacity c = 576 bits = 9 lanes.
 * Initially capacity lanes are 0.
 * Diffusion properties: Keccak-f round operations (theta, rho, pi, chi, iota).
 */

int main(void) {
    printf("--- 29. SHA-3 Keccak Capacity Lane Diffusion ---\n\n");
    printf("Parameters:\n");
    printf("  Total state size b = 1600 bits = 25 lanes (64 bits each)\n");
    printf("  Rate r             = 1024 bits = 16 lanes\n");
    printf("  Capacity c         =  576 bits =  9 lanes\n\n");

    printf("Initial State:\n");
    printf("  Rate lanes (P0):     16 lanes (all contain nonzero bits)\n");
    printf("  Capacity lanes:       9 lanes (all initialized to zero)\n\n");

    printf("Diffusion Analysis:\n");
    printf("1. In the first round of Keccak-f:\n");
    printf("   - Theta (theta) step XORs each bit with parity of adjacent columns.\n");
    printf("   - Chi (chi) step non-linearly combines bits across rows.\n");
    printf("   - After just ONE permutation round, nonzero bits from the 16 rate lanes\n"
           "     propagate into all 9 capacity lanes.\n");
    printf("2. Therefore, it takes only 1 round of the Keccak-f[1600] permutation\n"
           "   for all 9 capacity lanes to have at least one nonzero bit.\n");

    return 0;
}
