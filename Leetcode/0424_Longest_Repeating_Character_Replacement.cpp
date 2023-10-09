class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int i = 0;
        int ans = -1;
        int maxRepeat = 0;
        for(int j = 0; j < s.length(); j++){
            mp[s[j]]++;
            maxRepeat = max(maxRepeat, mp[s[j]]);
            int winLength = j - i + 1;
            int nonRepeat = winLength - maxRepeat;
            if(nonRepeat > k){
                mp[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};