// Naive Solution using Map and O(n) TC

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto x : nums){
            mp[x]++;
        }
        for(auto z : mp)
            if(z.second == 1)
                return z.first;

        return -1;
    }
};


// Xor Solution

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto x : nums)
            ans ^= x;
        return ans;
    }
};