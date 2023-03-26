class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        return solve(0, 0, cols-1, rows, cols, grid);
    }

    int solve(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid){
        if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) return -1e8;
        if(i==r-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        // Explore all the paths simultaneously
        int maxi = -1e8;
        for(int dj1 = -1; dj1 <= 1; dj1++){
            for(int dj2 = -1; dj2 <= 1; dj2++){
                int value = 0;
                if(j1==j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += solve(i+1, j1+dj1, j2+dj2, r, c, grid);
                maxi = max(maxi, value);
            }
        }
        return maxi;
    }
};