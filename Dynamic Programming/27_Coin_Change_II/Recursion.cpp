class Solution {
public:
    int solve(int ind, vector<int> &coins, int sum){
        if(ind == 0){
            return (sum%coins[0]==0);
        }
        int notTake = solve(ind-1, coins, sum);
        int take = 0;
        if(coins[ind] <= sum) take = solve(ind, coins, sum - coins[ind]);
        return take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return solve(n-1, coins, amount);
    }
};