#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int m = s1.size();
        const int n = s2.size();
        const int l = s3.size();

        // If the lengths don't match, return false
        if (m + n != l) return false;

        // Ensure s1 is the longer string for optimization
        if (m < n) return isInterleave(s2, s1, s3);

        // Memoization array
        vector<bool> memo(n + 1, false);
        memo[0] = true;

        // Initialize the first row of the DP table
        for (int i = 1; i <= n; ++i) {
            memo[i] = memo[i - 1] && (s2[i - 1] == s3[i - 1]);
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            memo[0] = memo[0] && (s1[i - 1] == s3[i - 1]);
            for (int j = 1; j <= n; ++j) {
                memo[j] = (memo[j] && (s1[i - 1] == s3[i + j - 1])) ||
                          (memo[j - 1] && (s2[j - 1] == s3[i + j - 1]));
            }
        }

        return memo[n];
    }
};

int main() {
    Solution solution;

    // Example 1
    string s1_1 = "aabcc", s2_1 = "dbbca", s3_1 = "aadbbcbcac";
    cout << "Input: s1 = \"" << s1_1 << "\", s2 = \"" << s2_1 << "\", s3 = \"" << s3_1 << "\"" << endl;
    cout << "Output: " << (solution.isInterleave(s1_1, s2_1, s3_1) ? "true" : "false") << endl;

    // Example 2
    string s1_2 = "aabcc", s2_2 = "dbbca", s3_2 = "aadbbbaccc";
    cout << "Input: s1 = \"" << s1_2 << "\", s2 = \"" << s2_2 << "\", s3 = \"" << s3_2 << "\"" << endl;
    cout << "Output: " << (solution.isInterleave(s1_2, s2_2, s3_2) ? "true" : "false") << endl;

    // Example 3
    string s1_3 = "", s2_3 = "", s3_3 = "";
    cout << "Input: s1 = \"" << s1_3 << "\", s2 = \"" << s2_3 << "\", s3 = \"" << s3_3 << "\"" << endl;
    cout << "Output: " << (solution.isInterleave(s1_3, s2_3, s3_3) ? "true" : "false") << endl;

    return 0;
}
