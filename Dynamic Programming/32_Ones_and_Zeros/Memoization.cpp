class Solution {
public:
    int solve(vector<string> &strs, int m, int n, int ind, vector<vector<vector<int>>> &dp){
        // Base Case
        if(m == 0 && n == 0) return 0;
        if(ind == strs.size()){
            return 0;
        }

        if(dp[ind][m][n] != -1) return dp[ind][m][n];

        int notTake = solve(strs, m, n, ind+1, dp);

        int take = 0;
        int cnt0 = count(strs[ind].begin(), strs[ind].end(), '0');
        int cnt1 = strs[ind].size() - cnt0;
        if(cnt0 <= m && cnt1 <= n){
            take = 1 + solve(strs, m-cnt0, n-cnt1, ind+1, dp);
        }

        return dp[ind][m][n] = max(take, notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return solve(strs, m, n, 0, dp);
    }
};