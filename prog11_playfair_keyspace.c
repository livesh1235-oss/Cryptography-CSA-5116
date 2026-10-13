#include <stdio.h>
#include <math.h>

/*
 * 11. Playfair Cipher Key Space Analysis:
 * - Total permutations of 25 letters: 25!
 * - Symmetries: Any 5x5 matrix shifted horizontally or vertically by rows/cols
 *   produces equivalent digraph encryption results (25 equivalent shifts).
 * - Effectively unique keys = 25! / 25 = 24!
 */

int main(void) {
    double total_keys = 1.0;
    for (int i = 1; i <= 25; i++) {
        total_keys *= i;
    }

    double unique_keys = total_keys / 25.0; // 24!

    double log2_total = log2(total_keys);
    double log2_unique = log2(unique_keys);

    printf("--- 11. Playfair Cipher Key Space Calculation ---\n\n");
    printf("1. Total theoretical keys (ignoring symmetries):\n");
    printf("   25! = %.6e\n", total_keys);
    printf("   Approximate power of 2: 2^(%.2f)\n\n", log2_total);

    printf("2. Effectively unique keys (accounting for cyclic shifts):\n");
    printf("   24! = 25! / 25 = %.6e\n", unique_keys);
    printf("   Approximate power of 2: 2^(%.2f)\n", log2_unique);

    return 0;
}
