class Solution {
public:
    int minCut(string s) {
         int n = s.length();
        vector<int> dp(n, 0);
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            int minCuts = i; // Max cuts needed would be `i` (cutting each character separately)
            for (int j = 0; j <= i; j++) {
                if (s[j] == s[i] && (i - j < 2 || palindrome[j + 1][i - 1])) {
                    palindrome[j][i] = true;
                    // If `j == 0`, then the whole substring `s[0:i+1]` is a palindrome, so no cuts needed
                    minCuts = (j == 0) ? 0 : min(minCuts, dp[j - 1] + 1);
                }
            }
            dp[i] = minCuts;
        }

        return dp[n - 1];
    }
};