class Solution {
public:
    int cap(vector<vector<char>> &board, int x, int y, int dx, int dy){
        while(x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] != 'B'){
            if(board[x][y] == 'p') return 1;
            x += dx;
            y += dy;
        }
        return 0;
    }

    int numRookCaptures(vector<vector<char>>& board) {
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j] == 'R')
                    return cap(board,i,j,0,1)+cap(board,i,j,0,-1)+cap(board,i,j,1,0)+cap(board,i,j,-1,0);
            }
        }
        return 0;
    }
};