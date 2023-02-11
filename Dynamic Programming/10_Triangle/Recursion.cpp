class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        return solve(triangle, 0, 0, n);
    }

    int solve(vector<vector<int>> &triangle, int i, int j, int n){
        if(i==n-1){
            return triangle[n-1][j];
        }
        int x1 = triangle[i][j] + solve(triangle, i+1, j, n);
        int x2 = triangle[i][j] + solve(triangle, i+1, j+1, n);

        return min(x1, x2);
    }
};