int knapsack(int n, int w, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp){
    if(n==0 || w==0){
        return 0;
    }
    
    if(dp[n][w] != -1) return dp[n][w];
    
    if(wt[n-1] <= w){
        return dp[n][w] = max(val[n-1] + knapsack(n-1, w-wt[n-1], wt, val, dp), knapsack(n-1, w, wt, val, dp));
    }
    else if(wt[n-1] > w){
        return dp[n][w] = knapsack(n-1, w, wt, val, dp);
    }
}

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    vector<vector<int>> dp(n+1, vector<int>(C+1, -1));
    return knapsack(n, C, B, A, dp);
}
