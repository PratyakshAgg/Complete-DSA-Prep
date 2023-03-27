#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 3, 2, 4};
    int n = 4;
    stack<int> st;
    vector<int> v;
    for(int i = n-1; i>=0; i--){
        if(st.size()==0) v.push_back(-1);
        else if(st.size()>0 && st.top()>arr[i]) v.push_back(st.top());
        else if(st.size()>0 && st.top()<=arr[i]){
            while(st.size()>0 && st.top()<=arr[i]){
                st.pop();
            }
            if(st.size()==0) v.push_back(-1);
            else v.push_back(st.top());
        }
        st.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    for(auto x : v){
        cout << x << " ";
    }
    return 0;
}