class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return solve(m-1, n-1, grid);
    }

    int solve(int x, int y, vector<vector<int>> &grid){
        if(x == 0 && y == 0) return grid[x][y];
        if(x < 0 || y < 0) return 1e9;

        int up = grid[x][y] + solve(x-1, y, grid);
        int left = grid[x][y] + solve(x, y-1, grid);

        return min(up, left);
    }
};