class Solution {
public:
    int solve(int ind, vector<int> &cost, vector<int> &dp){
        //Base Case 
        if(ind >= cost.size()){
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];

        int oneStep = cost[ind] + solve(ind+1, cost, dp);
        int twoSteps = cost[ind] + solve(ind+2, cost, dp);

        return dp[ind] = min(oneStep, twoSteps);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(solve(0, cost, dp), solve(1, cost, dp));
    }
};