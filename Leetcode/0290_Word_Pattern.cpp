class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string tmp = "";
        int i = 0;
        while(i < s.size()){
            if(s[i] == ' '){
                v.push_back(tmp);
                tmp = "";
            }
            else {
                tmp += s[i];
            }
            i++;
        }
        v.push_back(tmp);
        if(v.size() != pattern.size()) return false;

        unordered_map<char, string> mp;
        set<string> st;

        for(int i = 0; i < pattern.size(); i++){
            if(mp.find(pattern[i]) != mp.end()){
                if(v[i] == mp[pattern[i]]) continue;
                else return false;
            }
            else{
                if(st.find(v[i]) != st.end()){
                    return false;
                }else{
                    mp.insert({ pattern[i] , v[i]});
                    st.insert(v[i]);
                }
            }
        }
        return true;
    }
};