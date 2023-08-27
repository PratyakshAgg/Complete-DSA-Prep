class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;

        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(j == n-1){
                    dp[i][j] = matrix[i][j] == '0' ? 0 : 1;
                }
                else if(i == m-1){
                    dp[i][j] = matrix[i][j] == '0' ? 0 : 1;
                }
                else if(matrix[i][j] == '0'){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = 1 + min(min(dp[i+1][j], dp[i][j+1]), dp[i+1][j+1]);
                }
                res = max(res, dp[i][j]);
            }
        }
        return res*res;
    }
};