class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, obstacleGrid, dp);
    }
    
    int solve(int x, int y, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp){
        if(x>=0 && y>=0 && obstacleGrid[x][y] == 1) return 0;
        if(x==0 && y==0) return 1;
        if(x < 0 || y < 0) return 0;
        if(dp[x][y] != -1) return dp[x][y];
        int left = solve(x, y-1, obstacleGrid, dp);
        int top = solve(x-1, y, obstacleGrid, dp);
        return dp[x][y] = left + top;
    }
};