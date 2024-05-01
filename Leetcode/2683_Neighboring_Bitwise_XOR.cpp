class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xr = 0;
        for(auto x : derived){
            xr ^= x;
        }
        return (xr == 0);
    }
};