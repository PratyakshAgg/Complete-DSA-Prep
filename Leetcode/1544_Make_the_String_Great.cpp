/*
class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(abs(st.top()-s[i])==32) st.pop();
            else st.push(s[i]);
        }
        string ans;
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};
*/

class Solution {
public:
    string makeGood(string s) {
        string ans;
        for(int i = 0; i < s.size(); i++){
            ans.push_back(s[i]);
            while(ans.size() && abs(ans.back()-s[i+1])==32){
                ans.pop_back();
                i++;
            }
        }
        return ans;
    }
};