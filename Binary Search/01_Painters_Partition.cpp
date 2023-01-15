int painters(vector<int> &boards, int cap){
    int ans = 1;
    int remCap = cap;
    int n = boards.size();
    for(int i = 0; i < n; i++){
        if(boards[i] <= remCap){
            remCap -= boards[i];
        }
        else{
            ans++;
            remCap = cap - boards[i];
        }
    }
    return ans;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int max_val = 0;
    int sum = 0;
    int n = boards.size();
    for(int i = 0; i < n; i++){
        sum += boards[i];
        max_val = max(max_val, boards[i]);
    }
    int s = max_val;
    int e = sum;
    int ans = -1;
    while(s <= e){
        int m = s + (e-s)/2;
        int reqPainters = painters(boards, m);
        if(reqPainters <= k){
            ans = m;
            e = m-1;
        }
        else s=m+1;
    }
    return ans;
}