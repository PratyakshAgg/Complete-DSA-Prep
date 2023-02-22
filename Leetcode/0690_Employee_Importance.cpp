/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> m;
        for(auto x : employees) m[x->id] = x;
        int ans = 0;
        dfs(m, id, ans);
        return ans;
    }

    void dfs(unordered_map<int, Employee*> &m, int id, int &ans){
        ans += m[id]->importance;
        for(auto x : m[id]->subordinates) dfs(m, x, ans);
    }
};

/*
// BFS Solution
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> m;
        for(auto x : employees) m[x->id] = x;
        int ans = 0;
        queue<Employee*> q;
        q.push(m[id]);
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            for(auto x : p->subordinates) q.push(m[x]);
            ans += p->importance;
        }
        return ans;
    }
};
*/