class Solution {
public:
    void solve(int open, int close, int n, vector<string> &ans, string &tmp){
        if(tmp.size()==2*n){
            ans.push_back(tmp);
            return;
        }
        if(open < n){
            tmp.push_back('(');
            solve(open+1, close, n, ans, tmp);
            tmp.pop_back();
        }
        if(close < open){
            tmp.push_back(')');
            solve(open, close+1, n, ans, tmp);
            tmp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        vector<string> ans;
        string tmp;
        solve(open, close, n, ans, tmp);
        return ans;
    }
};