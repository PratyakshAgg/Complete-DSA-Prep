class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int limit = 2000 + a + b;
        queue<pair<int, int>> q;
        q.push({0, 1});
        unordered_set<int> visited;
        for(auto &x : forbidden){
            visited.insert(x);
        }
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto it = q.front();
                q.pop();
                int num = it.first;
                int forward = it.second;
                if(num==x) return ans;
                if(visited.count(num)>0) continue;
                visited.insert(num);
                if(forward){
                    int nxt = num-b;
                    if(nxt>=0) q.push({nxt, 0});
                }
                int nxt = num+a;
                if(nxt<=limit) q.push({nxt, 1});
            }
            ans++;
        }
        return -1;
    }
};