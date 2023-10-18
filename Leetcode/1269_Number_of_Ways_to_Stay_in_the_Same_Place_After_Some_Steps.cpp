class Solution {
public:
    const int MOD = 1e9 + 7;
    long long solve(int idx, int steps, int arrLen, vector<vector<long long>> &dp){
        // Base Case
        if(steps == 0){
            if(idx == 0){
                return 1;
            }
            else return 0;
        }

        if(idx < 0 || idx >= arrLen || steps < 0) return 0;

        if(dp[idx][steps] != -1) return dp[idx][steps];

        long long ways = solve(idx, steps - 1, arrLen, dp)%MOD;
        ways += solve(idx - 1, steps - 1, arrLen, dp)%MOD;
        ways += solve(idx + 1, steps - 1, arrLen, dp)%MOD;

        dp[idx][steps] = ways%MOD;

        return ways%MOD;
    }

    int numWays(int steps, int arrLen) {
        vector<vector<long long>> dp(min(arrLen, steps) + 1, vector<long long>(steps + 1, -1));
        return solve(0, steps, arrLen, dp);
    }
};