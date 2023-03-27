#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int n = 7;
    vector<int> v;
    stack<pair<int, int>> st;
    for(int i = 0; i < n; i++){
        if(st.size()==0) v.push_back(-1);
        else if(st.size() > 0 && st.top().first > arr[i]) v.push_back(st.top().second);
        else if(st.size() > 0 && st.top().first <= arr[i]){
            while(st.size() > 0 && st.top().first <= arr[i]){
                st.pop();
            }
            if(st.size()==0) v.push_back(-1);
            else v.push_back(st.top().second);
        }
        st.push({arr[i], i});
    }
    for(int i = 0; i < n; i++){
        v[i] = i - v[i];
        cout << v[i] << " ";
    }
    return 0;
}