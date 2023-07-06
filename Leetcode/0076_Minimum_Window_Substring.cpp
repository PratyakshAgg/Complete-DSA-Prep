class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        int i = 0, start = 0;
        int ans = INT_MAX;

        for(int j = 0; j < t.length(); j++){
            mp[t[j]]++;
        }
        int count = mp.size();

        for(int j = 0; j < s.length(); j++){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0) count--;
            }

            while(!count){
                if(j-i+1 < ans){
                    ans = j-i+1;
                    start = i;
                }
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]] == 1) count++;
                }
                i++;
            }
        }
        return ans == INT_MAX ? "" : s.substr(start, ans);
    }
};