class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1, 0), curr(amount+1, 0);
        for(int i = 0; i <= amount; i++){
            prev[i] = (i%coins[0]==0);
        }

        for(int ind = 1; ind < n; ind++){
            for(int sum = 0; sum <= amount; sum++){
                int notTake = prev[sum];
                int take = 0;
                if(coins[ind] <= sum) take = curr[sum - coins[ind]];
                curr[sum] = take + notTake;
            }
            prev = curr;
        }
        return prev[amount];
    }
};