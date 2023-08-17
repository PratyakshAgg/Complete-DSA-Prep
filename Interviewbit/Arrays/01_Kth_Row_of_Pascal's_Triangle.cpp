vector<int> Solution::getRow(int k) {
    vector<int> res;
    res.push_back(1);
    if(k == 0) return res;
    for(int i = 1; i < k; i++){
        res.push_back(res[i-1]*(k+1-i)/(i));
    }
    res.push_back(1);
    return res;
}
