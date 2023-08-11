class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1) return -1;
        if(n==1) return 1;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 0;
        queue<pair<int, pair<int, int>>> q;
        int row[] = {0, 1, 0, -1, -1, -1, 1, 1};
        int col[] = {1, 0, -1, 0, 1, -1, 1, -1};
        q.push({0, {0, 0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i = 0; i < 8; i++){
                int newr = r + row[i];
                int newc = c + col[i];
                if(newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 0 && dis + 1 < dist[newr][newc]){
                    dist[newr][newc] = dis + 1;
                    if(newr == n-1 && newc == n-1) return dist[newr][newc] + 1;
                    q.push({1+dis, {newr, newc}});
                }
            }
        }
        return -1;
    }
};