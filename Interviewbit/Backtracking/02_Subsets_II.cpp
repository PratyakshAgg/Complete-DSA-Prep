void solve(int ind, vector<int> &A, vector<vector<int>> &ans, vector<int> &ds){
    if(ind == A.size()){
        ans.push_back(ds);
        return;
    }    
    
    ds.push_back(A[ind]);
    solve(ind+1, A, ans, ds);
    ds.pop_back();
    while(ind+1 < A.size() && A[ind] == A[ind+1]) ind++;
    solve(ind+1, A, ans, ds);
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    vector<int> ds;
    solve(0, A, ans, ds);
    sort(ans.begin(), ans.end());
    return ans;
}
