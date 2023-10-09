class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(59, 0);
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i-1; j++){
                int prod = max(j, dp[j]) * max(i-j, dp[i-j]);
                dp[i] = max(dp[i], prod);
            }
        }
        return dp[n];
    }
};