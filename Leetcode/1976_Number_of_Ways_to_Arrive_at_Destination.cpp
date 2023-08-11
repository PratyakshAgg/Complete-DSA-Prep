class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long, long long>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<long long> dist(n, 1e18), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        int mod = (int)(1e9+7);

        while(!pq.empty()){
            long long node = pq.top().second;
            long long dis = pq.top().first;
            pq.pop();

            for(auto it : adj[node]){
                long long adjNode = it.first;
                long long w = it.second;
                if(dis + w < dist[adjNode]){
                    dist[adjNode] = dis + w;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node]%mod;
                }
                else if(dis + w == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};