class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(0, 1, prices, n, k, dp);
    }
    
    int solve(int ind, int buy, vector<int> &prices, int n, int cap, vector<vector<vector<int>>> &dp){
        if(cap == 0) return 0;
        if(ind == n) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        
        int profit = 0;
        
        if(buy){
            profit = max(-prices[ind] + solve(ind+1, 0, prices, n, cap, dp), 0 + solve(ind+1, 1, prices, n, cap, dp));
        }
        else{
            profit = max(prices[ind] + solve(ind+1, 1, prices, n, cap-1, dp), 0 + solve(ind+1, 0, prices, n, cap, dp));
        }
        return dp[ind][buy][cap] = profit;
    }
};