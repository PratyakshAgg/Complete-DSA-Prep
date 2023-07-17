class Solution {
public:
    void dfs(vector<vector<int>> &image, int x, int y, int m, int n, int c, int o){
        if(x < 0 || x >= m || y < 0 || y >= n || image[x][y] != o || image[x][y] == c)
            return;

        image[x][y] = c;

        dfs(image, x-1, y, m, n, c, o);
        dfs(image, x+1, y, m, n, c, o);
        dfs(image, x, y-1, m, n, c, o);
        dfs(image, x, y+1, m, n, c, o);

        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int ocol = image[sr][sc];
        dfs(image, sr, sc, m, n, color, ocol);
        return image;
    }
};