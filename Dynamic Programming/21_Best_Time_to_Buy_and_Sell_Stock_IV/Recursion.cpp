class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        return solve(0, 1, prices, n, k);
    }
    
    int solve(int ind, int buy, vector<int> &prices, int n, int cap){
        if(cap == 0 || ind == n) return 0;
        
        int profit = 0;
        
        if(buy){
            profit = max(-prices[ind] + solve(ind+1, 0, prices, n, cap), 0 + solve(ind+1, 1, prices, n, cap));
        }
        else{
            profit = max(prices[ind] + solve(ind+1, 1, prices, n, cap-1), 0 + solve(ind+1, 0, prices, n, cap));
        }
        return profit;
    }
};