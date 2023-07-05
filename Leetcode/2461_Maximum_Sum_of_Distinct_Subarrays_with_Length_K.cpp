class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long i = 0, sum = 0, mx = 0;
        int n = nums.size();

        for(int j = 0; j < n; j++){
            mp[nums[j]]++;
            sum += nums[j];
        
            if(j-i+1 == k){
                if(mp.size() == k) mx = max(mx, sum);
                sum -= nums[i];
                mp[nums[i]]--;
                if(!mp[nums[i]]) mp.erase(nums[i]);
                i++;
            }
        } 
        return mx;
    }
};