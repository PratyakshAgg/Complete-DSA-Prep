class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(triangle, 0, 0, n, dp);
    }

    int solve(vector<vector<int>> &triangle, int i, int j, int n, vector<vector<int>> &dp){
        if(i==n-1){
            return triangle[n-1][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int x1 = triangle[i][j] + solve(triangle, i+1, j, n, dp);
        int x2 = triangle[i][j] + solve(triangle, i+1, j+1, n, dp);

        return dp[i][j] = min(x1, x2);
    }
};