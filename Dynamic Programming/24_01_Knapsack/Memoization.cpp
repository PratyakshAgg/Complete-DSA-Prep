class Solution
{
    public:
    int knapsack(int w, int n, int wt[], int val[], vector<vector<int>> &dp){
        if(n == 0 || w == 0){
            return 0;
        }
        
        if(dp[n][w] != -1) return dp[n][w];
        
        if(wt[n-1] <= w){
            return dp[n][w] = max(val[n-1] + knapsack(w-wt[n-1], n-1, wt, val, dp), knapsack(w, n-1, wt, val, dp));
        }
        else if(wt[n-1] > w){
            return dp[n][w] = knapsack(w, n-1, wt, val, dp);
        }
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
       return knapsack(W, n, wt, val, dp);
    }
};