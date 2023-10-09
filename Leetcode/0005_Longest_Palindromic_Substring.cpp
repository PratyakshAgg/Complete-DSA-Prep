class Solution {
public:
    bool solve(vector<vector<bool>> &dp, int i, int j, string &s){
        if(i == j) return dp[i][j] = true;

        if(j - i == 1){
            if(s[i] == s[j]) return dp[i][j] = true;
            else return dp[i][j] = false;
        }

        if(s[i] == s[j] && dp[i+1][j-1] == true) return dp[i][j] = true;
        else return dp[i][j] = false;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int max_len = 0;
        int start_idx = -1;
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        for(int g = 0; g < n; g++){
            for(int i = 0, j = g; j < n; i++, j++){
                solve(dp, i, j, s);
                if(dp[i][j]){
                    if(j - i + 1 > max_len){
                        start_idx = i;
                        max_len = j - i + 1;
                    }
                }
            }
        }
        return s.substr(start_idx, max_len);
    }
};