class Solution {
public:
    set<pair<int, int>> s;
    int solve(int n, int i, int j){
        //Base Case
        if(i > n) return 1e9;
        if(i == n) return 0;

        if(s.find({i, j}) != s.end()){
            return 1e9;
        }
        s.insert({i, j});
        int copy = 1 + solve(n, i, i);
        int paste = 1 + solve(n, i+j, j);

        return min(copy, paste);
    }

    int minSteps(int n) {
        return solve(n, 1, 0);
    }
};