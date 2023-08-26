class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // Pushing in the indexes
        for(int i = 0; i < edges.size(); i++){
            edges[i].push_back(i);
        }
        // Sort the edges by weight
        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b){
            return a[2] < b[2];
        });
        int original_mst = getMST(n, edges, -1);
        vector<int> critical, pseudo;
        for(int i = 0; i < edges.size(); i++){
            if(original_mst < getMST(n, edges, i)){
                critical.push_back(edges[i][3]);
            }
            else if(original_mst == getMST(n, edges, -1, i)){
                pseudo.push_back(edges[i][3]);
            }
        }
        return {critical, pseudo};
    }

    int getMST(const int n, const vector<vector<int>> &edges, int exclude = -1, int include = -1){
        DisjointSet ds(n);
        int weight = 0;
        if(include != -1){
            weight += edges[include][2];
            ds.unionBySize(edges[include][0], edges[include][1]);
        }

        for(int i = 0; i < edges.size(); i++){
            if(i == exclude) continue;
            const auto &edge = edges[i];
            if(ds.findUPar(edge[0]) == ds.findUPar(edge[1])) continue;
            weight += edge[2];
            ds.unionBySize(edge[0], edge[1]);
        }
        for(int i = 0; i < n; i++){
            if(ds.findUPar(i) != ds.findUPar(0)) return 1e9+7;
        }
        return weight;
    }
};