class Solution {
public:
    int solve(vector<vector<int>> &dungeon, int i, int j){
        int m = dungeon.size();
        int n = dungeon[0].size();
        if(i == m || j == n) return 1e9;

        if(i == m-1 && j == n-1){
            return (dungeon[i][j] <= 0) ? -dungeon[i][j] + 1 : 1;
        }

        int left = solve(dungeon, i, j+1);
        int top = solve(dungeon, i+1, j);

        int minHealth = min(left, top) - dungeon[i][j];

        return (minHealth <= 0) ? 1 : minHealth;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        return solve(dungeon, 0, 0);
    }
};