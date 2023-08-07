class Solution {
public:
    string finalString(string s) {
        string res = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] != 'i'){
                res += s[i];
            }
            else{
                reverse(res.begin(), res.end());
            }
        }
        return res;
    }
};