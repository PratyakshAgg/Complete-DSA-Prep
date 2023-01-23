#include <bits/stdc++.h> 
using namespace std;
int solve(int ind, vector<int> &heights){
    if(ind == 0) return 0;
    int left = solve(ind-1, heights) + abs(heights[ind]- heights[ind-1]);
    int right = INT_MAX;
    if(ind > 1){
        right = solve(ind-2, heights) + abs(heights[ind] - heights[ind-2]);
    } 
    return min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    return solve(n-1, heights);
}