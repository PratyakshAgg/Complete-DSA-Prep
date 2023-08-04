class Solution {
public:
    int solve(int ind, string s, set<string> &st, vector<int> &dp){
        if(ind == s.size()){
            return dp[ind] = 1;
        }

        if(dp[ind] != -1) return dp[ind];

        string tmp;
        for(int i = ind; i < s.size(); i++){
            tmp += s[i];
            if(st.find(tmp) != st.end()){
                if(solve(i+1, s, st, dp)) return dp[i] =  1;
            }
        }
        return dp[ind] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto x : wordDict) st.insert(x);
        vector<int> dp(s.size()+1, -1);
        return solve(0, s, st, dp);
    }
};