class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<set<int>> adj(n);
        for(auto it : roads){
            adj[it[0]].insert(it[1]);
            adj[it[1]].insert(it[0]);
        }
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int temp = adj[i].size() + adj[j].size();

                if(adj[j].count(i)) temp--;

                ans = max(ans, temp);
            }
        }
        return ans;
    }
};