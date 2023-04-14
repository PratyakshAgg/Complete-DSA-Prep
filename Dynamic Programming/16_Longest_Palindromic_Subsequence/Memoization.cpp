class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return f(n, n, s1, s2, dp);
    }

    int f(int i, int j, string &text1, string &text2, vector<vector<int>> &dp){
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i-1] == text2[j-1]) return dp[i][j] = 1 + f(i-1, j-1, text1, text2, dp);

        return dp[i][j] = max(f(i-1, j, text1, text2, dp), f(i, j-1, text1, text2, dp));
    }
};