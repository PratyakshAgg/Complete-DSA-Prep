class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));
        for(int i = 0; i <= amount; i++){
            dp[0][i] = (i%coins[0]==0);
        }

        for(int ind = 1; ind < n; ind++){
            for(int sum = 0; sum <= amount; sum++){
                int notTake = dp[ind-1][sum];
                int take = 0;
                if(coins[ind] <= sum) take = dp[ind][sum - coins[ind]];
                dp[ind][sum] = take + notTake;
            }
        }
        return dp[n-1][amount];
    }
};