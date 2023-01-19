class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxMin = INT_MIN;
        for(int i = 0; i < m; i++){
            int x = INT_MAX;
            for(int j = 0; j < n; j++)
                x = min(x, matrix[i][j]);
            maxMin = max(maxMin, x);
        }

        int minMax = INT_MAX;
        for (int j = 0; j < n; j++) {
            int x = INT_MIN;
            for (int i = 0; i < m; i++)
                x = max(x, matrix[i][j]);
            minMax = min(minMax, x);
        }

        if (maxMin != minMax) return vector<int> { };
        return vector<int> { maxMin };
    }
};