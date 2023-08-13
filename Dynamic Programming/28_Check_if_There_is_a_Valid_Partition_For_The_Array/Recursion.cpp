class Solution {
public:
    bool solve(int i, vector<int> &nums){
        // Base Case
        if(i == nums.size()){
            return true;
        }

        // Case-1
        if(i+1 < nums.size() && nums[i+1] == nums[i]){
            if(solve(i+2, nums)) return true;

            // Case-2
            if(i+2 < nums.size() && nums[i+2] == nums[i]){
                if(solve(i+3, nums)) return true;
            }
        }

        // Case-3
        if(i+2 < nums.size() && nums[i+1] == nums[i]+1 && nums[i+2] == nums[i]+2){
            if(solve(i+3, nums)) return true;
        }
        return false;
    }

    bool validPartition(vector<int>& nums) {
        return solve(0, nums);
    }
};