class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int i = 0;
        int ans = INT_MIN;

        for(int j = 0; j < s.length(); j++){
            mp[s[j]]++;

            if(mp.size() == j-i+1){
                ans = max(ans, j-i+1);
            }
            else if(mp.size() < j-i+1){
                while(mp.size() < j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
            }
        }
        if(ans == INT_MIN) return 0;
        return ans;
    }
};