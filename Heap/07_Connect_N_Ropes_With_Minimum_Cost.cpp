long long connectRopes(int* arr, int n)
{
    // Your code goes here
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(int i = 0; i < n; i++){
        pq.push(arr[i]);
    }
    int cost = 0;
    while(pq.size()>1){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        cost = cost + x + y;
        pq.push(x+y);
    }
    return cost;
}
