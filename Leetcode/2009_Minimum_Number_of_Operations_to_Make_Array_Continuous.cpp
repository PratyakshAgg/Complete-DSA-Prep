class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        set<int> st(nums.begin(), nums.end());
        vector<int> temp(st.begin(), st.end());
        int res = INT_MAX;
        for(int i = 0; i < temp.size(); i++){
            int l = temp[i];
            int r = l + n - 1;
            
            int j = upper_bound(temp.begin(), temp.end(), r) - temp.begin();
            int within_range = j - i;
            int out_of_range = n - within_range;

            res = min(res, out_of_range);
        }
        return res;
    }
};