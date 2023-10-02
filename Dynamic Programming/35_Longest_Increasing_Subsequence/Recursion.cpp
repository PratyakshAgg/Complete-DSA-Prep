class Solution {
public:
    int solve(vector<int> &nums, int ind, int p){
        if(ind >= nums.size()) return 0;

        int take = 0;

        if(p == -1 || nums[ind] > nums[p]){
            take = 1 + solve(nums, ind+1, ind);
        }
        int skip = solve(nums, ind+1, p);

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, -1);
    }
};