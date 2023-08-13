class Solution {
public:
    bool solve(int i, vector<int> &nums, vector<int> &dp){
        // Base Case
        if(i == nums.size()){
            return true;
        }
        if(dp[i] != -1) return dp[i];

        // Case-1
        if(i+1 < nums.size() && nums[i+1] == nums[i]){
            if(solve(i+2, nums, dp)) return dp[i] = true;

            // Case-2
            if(i+2 < nums.size() && nums[i+2] == nums[i]){
                if(solve(i+3, nums, dp)) return dp[i] = true;
            }
        }

        // Case-3
        if(i+2 < nums.size() && nums[i+1] == nums[i]+1 && nums[i+2] == nums[i]+2){
            if(solve(i+3, nums, dp)) return dp[i] = true;
        }
        return dp[i] = false;
    }

    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp);
    }
};