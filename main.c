#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if s3 is an interleaving of s1 and s2
bool isInterleave(char* s1, char* s2, char* s3) {
    int m = strlen(s1);
    int n = strlen(s2);

    // If the lengths do not match, return false
    if (strlen(s3) != m + n) {
        return false;
    }

    // DP array to store the results for substrings of s1 and s2
    bool dp[n + 1];

    // Initialize dp array
    memset(dp, false, sizeof(dp));
    dp[0] = true;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 && j == 0) continue; // Skip the first cell (already initialized)

            bool current = false;
            if (i > 0 && s1[i - 1] == s3[i + j - 1]) {
                current = dp[j]; // If character from s1 matches, carry over the result
            }
            if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                current = current || dp[j - 1]; // If character from s2 matches, carry over the result
            }
            dp[j] = current; // Update the dp array for this (i, j) pair
        }
    }

    return dp[n]; // Final answer will be in dp[n], which corresponds to using all of s2
}

int main() {
    // Example 1
    char s1_1[] = "aabcc";
    char s2_1[] = "dbbca";
    char s3_1[] = "aadbbcbcac";
    printf("Input: s1 = \"%s\", s2 = \"%s\", s3 = \"%s\"\n", s1_1, s2_1, s3_1);
    printf("Output: %s\n", isInterleave(s1_1, s2_1, s3_1) ? "true" : "false");

    // Example 2
    char s1_2[] = "aabcc";
    char s2_2[] = "dbbca";
    char s3_2[] = "aadbbbaccc";
    printf("Input: s1 = \"%s\", s2 = \"%s\", s3 = \"%s\"\n", s1_2, s2_2, s3_2);
    printf("Output: %s\n", isInterleave(s1_2, s2_2, s3_2) ? "true" : "false");

    // Example 3
    char s1_3[] = "";
    char s2_3[] = "";
    char s3_3[] = "";
    printf("Input: s1 = \"%s\", s2 = \"%s\", s3 = \"%s\"\n", s1_3, s2_3, s3_3);
    printf("Output: %s\n", isInterleave(s1_3, s2_3, s3_3) ? "true" : "false");

    return 0;
}
