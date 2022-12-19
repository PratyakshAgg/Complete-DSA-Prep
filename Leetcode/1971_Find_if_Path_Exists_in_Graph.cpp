//BFS
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int, vector<int>> mp;
        for(auto e : edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, 0);
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr == end) return true;
            for(int node : mp[curr]){
                if(!visited[node]){
                    visited[node] = 1;
                    q.push(node);
                }
            }
        }
        return false;
    }
};

//DFS
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int, vector<int>> mp;
        for(auto e : edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, 0);
        stack<int> st;
        st.push(start);
        visited[start] = 1;
        while(!st.empty()){
            int curr = st.top();
            st.pop();
            if(curr == end) return true;
            for(int node : mp[curr]){
                if(!visited[node]){
                    visited[node] = 1;
                    st.push(node);
                }
            }
        }
        return false;
    }
};