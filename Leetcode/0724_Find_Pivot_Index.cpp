class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightSum = 0;
        for(auto x : nums) rightSum += x;
        int leftSum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(leftSum*2 == rightSum-nums[i]) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};