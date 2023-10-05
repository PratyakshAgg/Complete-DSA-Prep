class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int maj1 = 0, maj2 = 0;
        for(auto num : nums){
            if(num == maj1) cnt1++;
            else if(num == maj2) cnt2++;
            else if(cnt1 == 0){
                maj1 = num;
                cnt1++;
            }
            else if(cnt2 == 0){
                maj2 = num;
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        int freq1 = 0;
        int freq2 = 0;
        for(auto num : nums){
            if(num == maj1) freq1++;
            else if(num == maj2) freq2++;
        }

        if(freq1 > floor(n/3)) ans.push_back(maj1);
        if(freq2 > floor(n/3)) ans.push_back(maj2);
        return ans;
    }
};