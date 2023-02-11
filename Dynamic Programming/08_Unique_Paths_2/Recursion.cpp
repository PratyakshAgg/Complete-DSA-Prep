class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return solve(m-1, n-1, obstacleGrid);
    }
    
    int solve(int x, int y, vector<vector<int>> &obstacleGrid){
        if(x>=0 && y>=0 && obstacleGrid[x][y] == 1) return 0;
        if(x==0 && y==0) return 1;
        if(x < 0 || y < 0) return 0;
        int left = solve(x, y-1, obstacleGrid);
        int top = solve(x-1, y, obstacleGrid);
        return left + top;
    }
};