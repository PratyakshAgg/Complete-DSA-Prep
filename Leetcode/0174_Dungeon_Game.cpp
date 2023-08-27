class Solution {
public:
    int solve(vector<vector<int>> &dungeon, int i, int j, vector<vector<int>> &dp){
        int m = dungeon.size();
        int n = dungeon[0].size();
        if(i == m || j == n) return 1e9;

        if(i == m-1 && j == n-1){
            return (dungeon[i][j] <= 0) ? -dungeon[i][j] + 1 : 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int left = solve(dungeon, i, j+1, dp);
        int top = solve(dungeon, i+1, j, dp);

        int minHealth = min(left, top) - dungeon[i][j];

        return dp[i][j] = (minHealth <= 0) ? 1 : minHealth;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(dungeon, 0, 0, dp);
    }
};