class Solution {
public:
    char findTheDifference(string s, string t) {
        char xr = 0;
        for(char &c : s) xr ^= c;
        for(char &c : t) xr ^= c;
        return xr;
    }
};