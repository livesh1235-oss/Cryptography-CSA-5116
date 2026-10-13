#include <stdio.h>

/*
 * 38. Known Plaintext Attack on Hill Cipher (2x2)
 */

int mod26(int x) { int r = x % 26; return (r < 0) ? r + 26 : r; }

int modInverse(int a, int m) {
    a = mod26(a);
    for (int x = 1; x < m; x++) if ((a * x) % m == 1) return x;
    return -1;
}

int main(void) {
    int P[2][2] = {{12, 4}, {4, 19}}; // "me", "et"
    int C[2][2] = {{4, 10}, {14, 25}};

    printf("--- 38. Hill Cipher Known Plaintext Key Recovery ---\n");
    int detP = mod26(P[0][0]*P[1][1] - P[0][1]*P[1][0]);
    int inv = modInverse(detP, 26);
    if (inv == -1) return 1;

    int P_inv[2][2];
    P_inv[0][0] = mod26( P[1][1] * inv);
    P_inv[0][1] = mod26(-P[0][1] * inv);
    P_inv[1][0] = mod26(-P[1][0] * inv);
    P_inv[1][1] = mod26( P[0][0] * inv);

    int K[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            K[i][j] = mod26(P_inv[i][0]*C[0][j] + P_inv[i][1]*C[1][j]);
        }
    }
    printf("Recovered Key:\n [%2d %2d]\n [%2d %2d]\n", K[0][0], K[0][1], K[1][0], K[1][1]);
    return 0;
}
