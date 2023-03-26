#include <bits/stdc++.h>

bool solve(int ind, int target, vector<int> &arr){
    if(target==0) return true;
    if(ind==0) return (arr[0]==target);

    bool notTake = solve(ind-1, target, arr);
    bool take = false;
    if(arr[ind] <= target) take = solve(ind-1, target-arr[ind], arr);

    return take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return solve(n-1, k, arr);
}