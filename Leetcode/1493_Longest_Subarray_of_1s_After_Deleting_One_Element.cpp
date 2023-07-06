class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, ans = 0, count = 0;
        int n = nums.size();

        for(int j = 0; j < n; j++){
            if(nums[j] == 0) count++;
            while(count > 1){
                if(nums[i] == 0) count--;
                i++;
            }
            ans = max(ans, j-i);
        }
        return ans;
    }
};