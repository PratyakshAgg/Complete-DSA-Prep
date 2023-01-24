class Solution {
public:
    int solve(int ind, vector<int> &nums){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;

        int pick = nums[ind] + solve(ind-2, nums);
        int notPick = 0 + solve(ind-1, nums);

        return max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(n-1, nums);
    }
};