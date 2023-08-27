class Solution {
public:
    int solve(vector<vector<char>> &matrix, int i, int j, vector<vector<int>> &dp){
        if(i == matrix.size() || j == matrix[0].size()) return 0;
        if(matrix[i][j] != '1') return 0;
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = 1 + min(min(solve(matrix, i+1, j, dp), solve(matrix, i, j+1, dp)), solve(matrix, i+1, j+1, dp));
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int res = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                res = max(res, solve(matrix, i, j, dp));
            }
        }
        return res*res;
    }
};