class Solution {
public:
    bool solve(int a, int b, string s1, string s2, string s3, vector<vector<int>> &dp){
        if(a == s1.length() && b == s2.length() && a+b == s3.length()){
            return true;
        }
        if(a + b >= s3.length()) return false;
        if(dp[a][b] != -1) return dp[a][b];
        bool x = false, y = false;
        if(a != s1.length()){
            if(s1[a] == s3[a+b]){
                x = solve(a+1, b, s1, s2, s3, dp);
            }
        }
        if(b != s2.length()){
            if(s2[b] == s3[a+b]){
                y = solve(a, b+1, s1, s2, s3, dp);
            }
        }
        return dp[a][b] = x || y;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.size(), b = s2.size();
        if(s3.length() != a+b) return false;
        vector<vector<int>> dp(a+1, vector<int>(b+1, -1));
        return solve(0, 0, s1, s2, s3, dp);
    }
};