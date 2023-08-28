class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));

        for(int i = N-1; i >= 0; i--){
            int cnt0 = count(strs[i].begin(), strs[i].end(), '0');
            int cnt1 = strs[i].size() - cnt0;
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    int notTake = dp[i+1][j][k];
                    int take = 0;
                    if(cnt0 <= j && cnt1 <= k){
                        take = 1 + dp[i+1][j-cnt0][k-cnt1];
                    }
                    dp[i][j][k] = max(take, notTake);
                }
            }
        }
        return dp[0][m][n];
    }
};