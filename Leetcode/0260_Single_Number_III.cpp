class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int x = 0;
        for(auto num : nums){
            x ^= num;
        }
        x &= -x; //Only the last bit which is 1 remains
        vector<int> res = {0, 0};

        for(auto num : nums){
            if(x&num) res[0]^=num;
            else res[1]^=num;
        }
        return res;
    }
};