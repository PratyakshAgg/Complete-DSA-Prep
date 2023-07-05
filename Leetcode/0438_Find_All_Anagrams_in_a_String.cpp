class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp;
        int i = 0;
        int n = s.length();
        int k = p.length();
        vector<int> ans;

        for(int x = 0; x < k; x++){
            mp[p[x]]++;
        }

        int siz = mp.size();

        for(int j = 0; j < n; j++){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(!mp[s[j]]) siz--;
            }

            if(j-i+1 == k){
                if(siz==0) ans.push_back(i);
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]] == 1) siz++;
                }
                i++;
            }
        }
        return ans;
    }
};