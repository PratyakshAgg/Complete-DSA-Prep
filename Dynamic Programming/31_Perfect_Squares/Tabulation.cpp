class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int ind = 1; ind <= n; ind++){
            for(int i = 1; i*i <= ind; i++){
                dp[ind] = min(dp[ind], 1 + dp[ind-i*i]);
            }
        }
        return dp[n];
    }
};