class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board){
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col]=='X' || vis[row][col]){
            return;
        }
        vis[row][col] = 1;

        dfs(row+1, col, vis, board);
        dfs(row, col+1, vis, board);
        dfs(row-1, col, vis, board);
        dfs(row, col-1, vis, board);
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O' && !vis[0][i]){
                dfs(0, i, vis, board);
            }
            if(board[m-1][i] == 'O' && !vis[m-1][i]){
                dfs(m-1, i, vis, board);
            }
        }

        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                dfs(i, 0, vis, board);
            }
            if(board[i][n-1] == 'O' && !vis[i][n-1]){
                dfs(i, n-1, vis, board);
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};