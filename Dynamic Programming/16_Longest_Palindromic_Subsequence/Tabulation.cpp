class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        int n = s.size();
        reverse(s.begin(), s.end());
        string s2 = s;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = 0; i <=n; i++) dp[i][0] = 0;
        for(int j = 0; j <= n; j++) dp[0][j] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][n];
    }
};