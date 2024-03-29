class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        st.insert({0, S});
        while(!st.empty()){
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);
            for(auto it : adj[node]){
                int wt = it[1];
                int v = it[0];
                
                if(dis + wt < dist[v]){
                    if(dist[v] != 1e9) st.erase({dist[v], v});
                    dist[v] = dis + wt;
                    st.insert({dist[v], v});
                }
            }
        }
        return dist;
    }
};