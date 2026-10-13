#include <stdio.h>

/*
 * 13. Known Plaintext Attack on Hill Cipher (2x2)
 * C = P * K (mod 26)  =>  K = P^(-1) * C (mod 26)
 */

int mod26(int x) {
    int r = x % 26;
    return (r < 0) ? r + 26 : r;
}

int modInverse(int a, int m) {
    a = mod26(a);
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1;
}

int main(void) {
    // Suppose known plaintext block pairs:
    // P1 = "me" = [12, 4], C1 = [4, 10]
    // P2 = "et" = [4, 19], C2 = [14, 25]
    // P matrix: [12 4; 4 19]
    // C matrix: [4 10; 14 25]
    int P[2][2] = {{12, 4}, {4, 19}};
    int C[2][2] = {{4, 10}, {14, 25}};

    printf("--- 13. Hill Cipher Known Plaintext Analysis ---\n");
    printf("Plaintext matrix P:\n [%2d %2d]\n [%2d %2d]\n", P[0][0], P[0][1], P[1][0], P[1][1]);
    printf("Ciphertext matrix C:\n [%2d %2d]\n [%2d %2d]\n\n", C[0][0], C[0][1], C[1][0], C[1][1]);

    int detP = mod26(P[0][0]*P[1][1] - P[0][1]*P[1][0]);
    int detP_inv = modInverse(detP, 26);

    if (detP_inv == -1) {
        printf("Determinant of P has no modular inverse. Attack needs another pair.\n");
        return 1;
    }

    int P_inv[2][2];
    P_inv[0][0] = mod26( P[1][1] * detP_inv);
    P_inv[0][1] = mod26(-P[0][1] * detP_inv);
    P_inv[1][0] = mod26(-P[1][0] * detP_inv);
    P_inv[1][1] = mod26( P[0][0] * detP_inv);

    // K = P_inv * C mod 26
    int K[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            K[i][j] = mod26(P_inv[i][0] * C[0][j] + P_inv[i][1] * C[1][j]);
        }
    }

    printf("Recovered Key Matrix K:\n [%2d %2d]\n [%2d %2d]\n", K[0][0], K[0][1], K[1][0], K[1][1]);
    return 0;
}
