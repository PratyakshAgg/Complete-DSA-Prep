class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            s.insert(nums[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int numb = nums[i];
            if(s.find(numb-1) != s.end()) continue;
            while(s.find(numb) != s.end()){
                numb++;
            }
            ans = max(ans, numb-nums[i]);
        }
        return ans;
    }
};