/*
Three conditions have to be fulfilled if the nodes form a valid binary tree.
1) There should be only one root.
2) Each node should have only one parent.
3) All nodes should be connected (There must be only one component).
*/

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> child_to_parent;

        for(int i = 0; i < n; i++){
            int node = i;
            int leftC = leftChild[i];
            int rightC = rightChild[i];

            if(leftC != -1){
                adj[node].push_back(leftC);
                if(child_to_parent.find(leftC) != child_to_parent.end()) return false;
                child_to_parent[leftC] = node;
            }

            if(rightC != -1){
                adj[node].push_back(rightC);
                if(child_to_parent.find(rightC) != child_to_parent.end()) return false;
                child_to_parent[rightC] = i;
            }
        }

        int root = -1;
        for(int i = 0; i < n; i++){
            if(child_to_parent.find(i) == child_to_parent.end()){
                if(root != -1) return false;
                root = i;
            }
        }

        if(root == -1) return false;

        // BFS/DFS to check if the nodes are connected
        int cnt = 0;
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(root);
        cnt = 1;
        vis[root] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto x : adj[node]){
                if(!vis[x]){
                    vis[x] = true;
                    cnt++;
                    q.push(x);
                }
            }
        }
        return cnt == n;
    }
};



/*
DSU Approach:
class Solution {
public:
    vector<int> parent; 
    int components;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool Union(int p , int c){
        if(find(c) != c) return false;
        if(find(p) == find(c)) return false;
        parent[c] = p;
        components -= 1;
        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        components = n;
        parent.resize(n);
        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }
        for(int i = 0; i < n; i++){
            int node = i;
            int lc = leftChild[node];
            int rc = rightChild[node];

            if(lc != -1 && Union(node, lc) == false) return false;

            if(rc != -1 && Union(node, rc) == false) return false;
        }

        return components == 1;    
    }
};
*/