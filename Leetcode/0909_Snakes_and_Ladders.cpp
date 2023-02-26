class Solution {
public:
    void getCoordinates(int n, int s, int &row, int &col){
        int rowS = (s-1)/n;
        row = n-1 - (s-1)/n;
        col = (s-1)%n;
        if(rowS%2==1)
            col = n-1-col;
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> vis(n*n+1, false);
        vis[1] = true;
        queue<pair<int, int>> q;
        q.push({1, 0});
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int row, col;
            int s = p.first;
            int dist = p.second;
            if(s==n*n) return dist;
            for(int i = 1; s+i <= n*n && i <= 6; i++){
                getCoordinates(n, s+i, row, col);
                int sfinal = board[row][col]==-1?s+i:board[row][col];
                if(vis[sfinal]==false){
                    vis[sfinal] = true;
                    q.push({sfinal,dist+1});
                }   
            }
        }
        return -1;
    }
};