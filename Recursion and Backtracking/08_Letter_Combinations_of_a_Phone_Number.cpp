class Solution {
public:
    void solve(int ind, string &digits, vector<string> &pad, vector<string> &combs, string &ans){
        if(ind == digits.size()){
            combs.push_back(ans);
            return;
        }

        string value = pad[digits[ind] - '0'];
        for(int i = 0; i < value.size(); i++){
            ans.push_back(value[i]);
            solve(ind+1, digits, pad, combs, ans);
            ans.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> combs;
        string ans;
        solve(0, digits, pad, combs, ans);
        return combs;
    }
};