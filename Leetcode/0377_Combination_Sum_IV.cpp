class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        long long mod = 1e18 + 7;
        for(int i = 1; i <= target; i++){
            for(int j = 0; j < n; j++){
                if(i - nums[j] >= 0) dp[i] += dp[i-nums[j]]%mod;
            }
        }
        return dp[target];
    }
};