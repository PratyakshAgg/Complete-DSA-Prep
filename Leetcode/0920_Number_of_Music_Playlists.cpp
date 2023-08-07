class Solution {
public:
    const int MOD = 1e9 + 7;
    long solve(int count_song, int count_unique, int n, int goal, int k, vector<vector<int>> &dp){
        // Base Case
        if(count_song == goal){
            if(count_unique == n){
                return 1;
            }
            return 0;
        }
        if(dp[count_song][count_unique] != -1) return dp[count_song][count_unique];
        long ans = 0;

        // Option-1: Play Unique Song
        if(count_unique < n) ans += (n-count_unique)*solve(count_song + 1, count_unique + 1, n, goal, k, dp);

        // Option-2: Replay a Song
        if(k < count_unique) ans += (count_unique-k)*solve(count_song + 1, count_unique, n, goal, k, dp);

        return dp[count_song][count_unique] = ans%MOD;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(goal + 1, vector<int>(n+1, -1));
        return solve(0, 0, n, goal, k, dp);
    }
};