class Solution{   
public:
    int knapsack(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp){
        if(sum==0) return 1;
        if(ind==0) return 0;
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        if(arr[ind-1] > sum) return dp[ind][sum] = knapsack(ind-1, sum, arr, dp);
        
        return dp[ind][sum] = knapsack(ind-1, sum, arr, dp) || knapsack(ind-1, sum - arr[ind-1], arr, dp);
    }

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        if(knapsack(n, sum, arr, dp)){
            return true;
        }
        else return false;
    }
};