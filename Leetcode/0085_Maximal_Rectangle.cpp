class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> v;
        for(int i = 0; i < cols; i++){
            v.push_back(int(matrix[0][i]-'0'));
        }
        int ans = mah(v);
        for(int i = 1; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j]=='0') v[j]=0;
                else v[j]+=int(matrix[i][j]-'0');
            }
            ans = max(ans, mah(v));
        }
        return ans;
    }

    int mah(vector<int> heights){
        heights.push_back(0);
        int n = heights.size();
        stack<int> st;
        int i = 0, h = 0, j = 0;
        int ans = 0;
        while(i < n){
            if(st.size()==0 || heights[i] > heights[st.top()]){
                st.push(i);
                i++;
            }
            else{
                h = heights[st.top()];
                st.pop();
                j = st.empty() ? -1 : st.top();
                ans = max(ans, h*(i-j-1));
            }
        }
        return ans;
    }
};