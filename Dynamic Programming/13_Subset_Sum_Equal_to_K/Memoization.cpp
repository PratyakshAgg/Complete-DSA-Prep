#include <bits/stdc++.h>

bool solve(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target==0) return true;
    if(ind==0) return (arr[0]==target);
    if(dp[ind][target] != -1) return dp[ind][target];

    bool notTake = solve(ind-1, target, arr, dp);
    bool take = false;
    if(arr[ind] <= target) take = solve(ind-1, target-arr[ind], arr, dp);

    return dp[ind][target] = take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return solve(n-1, k, arr, dp);
}
