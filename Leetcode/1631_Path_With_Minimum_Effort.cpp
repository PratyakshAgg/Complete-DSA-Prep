class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(rows, vector<int>(cols, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        int row[] = {0, 1, 0, -1};
        int col[] = {1, 0, -1, 0};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int r = it.second.first;
            int c = it.second.second;
            int diff = it.first;
            if(r == rows-1 && c == cols-1) return diff;

            for(int i = 0; i < 4; i++){
                int newr = r + row[i];
                int newc = c + col[i];
                if(newr >= 0 && newr < rows && newc >= 0 && newc < cols){
                    int newEffort = max(diff, abs(heights[r][c] - heights[newr][newc]));
                    if(newEffort < dist[newr][newc]){
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        return 0;
    }
};