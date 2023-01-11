class Solution {
public:
    int solve(int i, string &s, unordered_set<string> &st, string temp){
        if(i == s.size()) return 0;
        else{
            temp += s[i];
            int op1 = INT_MIN/2, op2 = INT_MIN/2;
            if(st.find(temp) == st.end()){
                st.insert(temp);
                op1 = 1 + solve(i+1, s, st, "");
                st.erase(temp);
            }
            op2 = solve(i+1, s, st, temp);
            return max(op1, op2);
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return solve(0, s, st, "");
    }
};