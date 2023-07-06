class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char, int> mp;
        int ans = 0;
        int i = 0;

        for(int j = 0; j < s.length(); j++){
            mp[s[j]]++;

            if(j-i+1 == 3){
                if(mp.size()==3) ans++;
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};