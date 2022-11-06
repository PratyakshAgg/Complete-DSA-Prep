class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() < 1) return {};
        unordered_map <int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            int comp = target - nums[i];
            auto it = mp.find(comp);
            if(it != mp.end())
                return {it->second, i};
            mp[nums[i]] = i;
        }
        return {};
    }
};