class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            pos += nums[i];
            if(pos == 0) ans++;
        }
        return ans;
    }
};