class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        for(int i = 0; i < N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(), s2.size());
            for(int j = 0; j < len; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        queue<int> q;
        vector<int> topo;
        vector<int> indegree(K, 0);
        for(int i = 0; i < K; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        for(int i = 0;  i < K; i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        string ans = "";
        for(auto it : topo){
            ans += char(it + 'a');
        }
        return ans;
    }
};