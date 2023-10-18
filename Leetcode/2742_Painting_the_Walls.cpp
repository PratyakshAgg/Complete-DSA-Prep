class Solution {
public:
    int n;
    int dp[501][501];

    int solve(int idx, int remain, vector<int> &cost, vector<int> &time){
        // Base Case
        if(remain <= 0) return 0;
        if(idx >= n) return 1e9;
        if(dp[idx][remain] != -1) return dp[idx][remain];

        int paint_idx = cost[idx] + solve(idx+1, remain-1-time[idx], cost, time);
        int no_paint = solve(idx+1, remain, cost, time);

        return dp[idx][remain] = min(paint_idx, no_paint);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n, cost, time);    
    }
};