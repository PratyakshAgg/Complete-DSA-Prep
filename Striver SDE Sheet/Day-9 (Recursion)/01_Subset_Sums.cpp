void solve(int ind, int sum, vector<int> &num, int n, vector<int> &sumSubset){
    if(ind == n){
        sumSubset.push_back(sum);
        return;
    }
    solve(ind+1, sum+num[ind], num, n, sumSubset);
    
    solve(ind+1, sum, num, n, sumSubset);
}

vector<int> subsetSum(vector<int> &num)
{
    int n = num.size();
    vector<int> sumSubset;
    solve(0, 0, num, n, sumSubset);
    sort(sumSubset.begin(), sumSubset.end());
    return sumSubset;
}