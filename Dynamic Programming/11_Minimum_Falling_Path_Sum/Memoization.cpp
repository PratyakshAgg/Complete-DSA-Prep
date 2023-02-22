class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int mini = 1e9;
        for(int i = 0; i < n; i++){
            mini = min(mini, solve(n, matrix, n-1, i, dp));
        }
        return mini;
    }

    int solve(int n, vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp){
        if(j < 0 || j >= n) return 1e9;
        if(i == 0) return matrix[0][j];
        if(dp[i][j] != -1) return dp[i][j];

        int u = matrix[i][j] + solve(n, matrix, i-1, j, dp);
        int ld = matrix[i][j] + solve(n, matrix, i-1, j-1, dp);
        int rd = matrix[i][j] + solve(n, matrix, i-1, j+1, dp);

        return dp[i][j] = min(u, min(ld, rd));
    }
};