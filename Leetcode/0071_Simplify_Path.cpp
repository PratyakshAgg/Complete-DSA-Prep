class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string ans;

        for(int i = 0; i < path.size(); i++){
            if(path[i]=='/') continue;
            string temp;
            while(i < path.size() && path[i] != '/'){
                temp += path[i];
                i++;
            }
            if(temp == ".") continue;
            else if(temp == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else st.push(temp);
        }

        stack<string> st1;

        while(!st.empty()){
            st1.push(st.top());
            st.pop();
        }

        while(!st1.empty()){
            ans += "/" + st1.top();
            st1.pop();
        }

        if(ans.size() == 0)
            return "/";
        
        return ans;
    }
};