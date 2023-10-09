class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, nums1, nums2, dp);
    }

    int solve(int i, int j, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp){
        // Base case
        if(i < 0 || j < 0) return INT_MIN;

        if(dp[i][j] != -1) return dp[i][j];
        
        int res = INT_MIN;

        res = max(nums1[i]*nums2[j] + max(0, solve(i-1, j-1, nums1, nums2, dp)), max(solve(i-1, j, nums1, nums2, dp), solve(i, j-1, nums1, nums2, dp)));

        return dp[i][j] = res;
    }
};