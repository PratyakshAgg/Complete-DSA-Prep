class Solution {
  private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &vec,
    int row0, int col0){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0 || vis[row][col]){
            return;
        }
        vis[row][col] = 1;
        vec.push_back({row-row0, col-col0});
        
        dfs(row+1, col, vis, grid, vec, row0, col0);
        dfs(row, col+1, vis, grid, vec, row0, col0);
        dfs(row-1, col, vis, grid, vec, row0, col0);
        dfs(row, col-1, vis, grid, vec, row0, col0);
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int, int>> vec;
                    dfs(i, j, vis, grid, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};