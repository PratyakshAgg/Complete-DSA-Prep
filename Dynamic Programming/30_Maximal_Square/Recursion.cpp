class Solution {
public:
    int solve(vector<vector<char>> &matrix, int i, int j){
        if(i == matrix.size() || j == matrix[0].size()) return 0;
        if(matrix[i][j] != '1') return 0;

        return 1 + min(min(solve(matrix, i+1, j), solve(matrix, i, j+1)), solve(matrix, i+1, j+1));
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                res = max(res, solve(matrix, i, j));
            }
        }
        return res*res;
    }
};