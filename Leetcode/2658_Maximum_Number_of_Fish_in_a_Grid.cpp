class Solution {
public:
    int dfs(vector<vector<int>> &grid, int i, int j){
        if( i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] != 0){
            int tmp = grid[i][j];
            grid[i][j] = 0;
            return tmp + dfs(grid, i+1, j) + dfs(grid, i-1, j) + dfs(grid, i, j-1) + dfs(grid, i, j+1);
        }
        return 0;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0) ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};