class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(m-1, n-1, grid, dp);
    }

    int solve(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(x == 0 && y == 0) return grid[x][y];
        if(x < 0 || y < 0) return 1e9;
        if(dp[x][y] != -1) return dp[x][y];

        int up = grid[x][y] + solve(x-1, y, grid, dp);
        int left = grid[x][y] + solve(x, y-1, grid, dp);

        return dp[x][y] = min(up, left);
    }
};