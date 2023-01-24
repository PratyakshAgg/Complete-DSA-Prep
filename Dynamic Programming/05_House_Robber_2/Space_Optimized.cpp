class Solution {
public:
    int robcalc(vector<int>& val) {
        int n = val.size();
        if(n==1) return val[0];
        int prevans2 = val[0];
        int prevans = max(val[1], val[0]);
        int currans = prevans;
        for(int i = 2; i < n; i++){
            currans = max(prevans, prevans2 + val[i]);
            prevans2 = prevans;
            prevans = currans;
        }
        return currans;
    }
    
    
    long long int rob(vector<int>& nums) {
        vector<int> t1, t2;
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i = 0; i < n; i++){
            if(i != 0) t1.push_back(nums[i]);
            if(i != n-1) t2.push_back(nums[i]);
        }
        return max(robcalc(t1), robcalc(t2));
    }
    
    
};