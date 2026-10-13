#include <stdio.h>
#include <string.h>

/*
 * Scenario 5: Legacy Transposition in Corporate Communication
 * Ciphertext: "WECRLTEERDSOEEFEAOCAIVDEN"
 * Method: Rail Fence Transposition Cipher with Depth = 3
 */

void decrypt_rail_fence(const char *cipher, char *plain, int rails) {
    int len = strlen(cipher);
    char rail_matrix[rails][len];
    memset(rail_matrix, '\0', sizeof(rail_matrix));

    // Mark the zigzag trajectory
    int row = 0, dir = 1;
    for (int i = 0; i < len; i++) {
        rail_matrix[row][i] = '*';
        if (row == 0) dir = 1;
        else if (row == rails - 1) dir = -1;
        row += dir;
    }

    // Fill the marked positions with ciphertext characters
    int idx = 0;
    for (int r = 0; r < rails; r++) {
        for (int c = 0; c < len; c++) {
            if (rail_matrix[r][c] == '*' && idx < len) {
                rail_matrix[r][c] = cipher[idx++];
            }
        }
    }

    // Read characters along the zigzag pattern
    row = 0; dir = 1;
    for (int i = 0; i < len; i++) {
        plain[i] = rail_matrix[row][i];
        if (row == 0) dir = 1;
        else if (row == rails - 1) dir = -1;
        row += dir;
    }
    plain[len] = '\0';
}

int main(void) {
    const char *cipher = "WECRLTEERDSOEEFEAOCAIVDEN";
    char recovered[64];
    int rails = 3;

    printf("--- Question 5: Rail Fence Transposition Reversal (Depth = 3) ---\n\n");
    printf("Received Ciphertext: %s (Length = %lu)\n", cipher, strlen(cipher));

    decrypt_rail_fence(cipher, recovered, rails);

    printf("Recovered Message:   %s\n", recovered);
    printf("Formatted Message:   \"WE ARE DISCOVERED FLEE AT ONCE\"\n");

    return 0;
}
