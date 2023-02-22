class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = 1e9;
        for(int i = 0; i < n; i++){
            mini = min(mini, solve(n, matrix, n-1, i));
        }
        return mini;
    }

    int solve(int n, vector<vector<int>> &matrix, int i, int j){
        if(j < 0 || j >= n) return 1e9;
        if(i == 0) return matrix[0][j];

        int u = matrix[i][j] + solve(n, matrix, i-1, j);
        int ld = matrix[i][j] + solve(n, matrix, i-1, j-1);
        int rd = matrix[i][j] + solve(n, matrix, i-1, j+1);

        return min(u, min(ld, rd));
    }
};