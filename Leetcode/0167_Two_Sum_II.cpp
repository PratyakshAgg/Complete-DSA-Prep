class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n-1;
        while(true){
            if(nums[i] + nums[j] < target){
                i++;
            }
            else if(nums[i] + nums[j] > target){
                j--;
            }
            else return {i+1, j+1};
        }
        return {};
    }
};