class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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