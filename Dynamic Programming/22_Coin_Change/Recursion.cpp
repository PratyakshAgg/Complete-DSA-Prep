class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans =  f(n-1, coins, amount);
        if(ans >= 1e9) return -1;
        return ans;
    }

    int f(int ind, vector<int> &coins, int amount){
        if(ind == 0){
            if(amount % coins[ind] == 0) return amount / coins[ind];
            else return 1e9;
        }

        int notTake = 0 + f(ind-1, coins, amount);

        int take = INT_MAX;    
        if(coins[ind] <= amount) take = 1 + f(ind, coins, amount - coins[ind]);

        return min(notTake, take); 
    }
};