class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if(n==1 || n==2) return true;
        
        for(int i = 0; i < n-1; i++){
            int sum = nums[i] + nums[i+1];
            if(sum >= m) return true;
        }
        return false;
    }
};