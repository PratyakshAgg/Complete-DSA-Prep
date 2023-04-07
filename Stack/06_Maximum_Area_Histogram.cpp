#include <bits/stdc++.h>
using namespace std;

int main() {
    int heights[] = {6, 2, 5, 4, 5, 1, 6};
    vector<int> left;
    stack<pair<int, int>> s;
    int pseudo = -1;
    int n = 7;
    for(int i = 0; i < n; i++){
        if(s.size()==0) left.push_back(pseudo);
        else if(s.size() > 0 && s.top().first < heights[i]) left.push_back(s.top().second);
        else if(s.size() > 0 && s.top().first >= heights[i]){
            while(s.size()>0 && s.top().first >= heights[i]){
                s.pop();
            }
            if(s.size()==0) left.push_back(pseudo);
            else left.push_back(s.top().second);
        }
        s.push({heights[i], i});
    }
    
    int p = n;
    vector<int> right;
    stack<pair<int, int>> st;
    for(int i = n-1; i>=0; i--){
        if(st.size()==0) right.push_back(p);
        else if(st.size()>0 && st.top().first<heights[i]) right.push_back(st.top().second);
        else if(st.size()>0 && st.top().first>=heights[i]){
            while(st.size()>0 && st.top().first>=heights[i]){
                st.pop();
            }
            if(st.size()==0) right.push_back(p);
            else right.push_back(st.top().second);
        }
        st.push({heights[i], i});
    }   
    reverse(right.begin(), right.end());

    vector<int> width;
    for(int i = 0; i < n; i++){
        width.push_back(right[i]-left[i]-1);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        int x = width[i]*heights[i];
        ans = max(ans, x);
    }

    cout << ans << endl;

    return 0;
}