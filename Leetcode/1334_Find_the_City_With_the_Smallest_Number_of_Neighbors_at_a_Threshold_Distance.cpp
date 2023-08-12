class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int, int>> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int cityNo, cntCity=1e9;

        for(int i = 0; i < n; i++){
            vector<int> dist(n, 1e9);
            dist[i] = 0;
            pq.push({0, i});
            while(!pq.empty()){
                int dis = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                for(auto it : adj[node]){
                    int adjNode = it.first;
                    int wt  = it.second;
                    if(dis + wt < dist[adjNode]){
                        dist[adjNode] = dis + wt;
                        pq.push({dist[adjNode], adjNode});
                    }
                }
            }
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(dist[j] <= distanceThreshold) cnt++;
            }
            if(cnt <= cntCity){
                cntCity = cnt;
                cityNo = i;
            }
        }
        return cityNo;
    }
};