class Solution {
public:
    int solve(int ind, vector<int> &coins, int sum, vector<vector<int>> &dp){
        if(ind == 0){
            return (sum%coins[0]==0);
        }

        if(dp[ind][sum] != -1) return dp[ind][sum];

        int notTake = solve(ind-1, coins, sum, dp);
        int take = 0;
        if(coins[ind] <= sum) take = solve(ind, coins, sum - coins[ind], dp);
        return dp[ind][sum] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return solve(n-1, coins, amount, dp);
    }
};