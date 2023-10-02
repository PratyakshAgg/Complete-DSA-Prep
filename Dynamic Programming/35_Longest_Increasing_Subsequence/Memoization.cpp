class Solution {
public:
    int solve(vector<int> &nums, int ind, int p, vector<vector<int>> &dp){
        if(ind >= nums.size()) return 0;

        if(p != -1 && dp[ind][p] != -1) return dp[ind][p];

        int take = 0;

        if(p == -1 || nums[ind] > nums[p]){
            take = 1 + solve(nums, ind+1, ind, dp);
        }
        int skip = solve(nums, ind+1, p, dp);

        if(p != -1) dp[ind][p] = max(take, skip);

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(nums, 0, -1, dp);
    }
};