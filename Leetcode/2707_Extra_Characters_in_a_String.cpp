class Solution {
public:
    int solve(int ind, string &s, unordered_map<string, int> &mp, vector<int> &dp){
        //Base Case
        if(ind >= s.size()) return 0;
        if(dp[ind] != -1) return dp[ind];

        string tmp = "";
        int notPick = 1 + solve(ind+1, s, mp, dp);
        int pick = INT_MAX;
        for(int i = ind; i < s.size(); i++){
            tmp += s[i];
            if(mp[tmp]){
                pick = min(pick, solve(i+1, s, mp, dp));
            }
        }
        return dp[ind] = min(pick, notPick);
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, int> mp;
        vector<int> dp(s.size()+1, -1);
        for(auto it : dictionary){
            mp[it]++;
        }
        return solve(0, s, mp, dp);
    }
};