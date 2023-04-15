class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve(0, 1, prices, n);
    }

    int solve(int ind, int buy, vector<int> &prices, int n){
        if(ind==n) return 0;

        int profit = 0;

        if(buy){
            profit = max(-prices[ind] + solve(ind+1, 0, prices, n), 0 + solve(ind+1, 1, prices, n));
        }

        else{
            profit = max(prices[ind] + solve(ind+1, 1, prices, n), 0 + solve(ind+1, 0, prices, n));
        }
        return profit;
    }
};