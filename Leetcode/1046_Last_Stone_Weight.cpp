class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto x : stones){
            pq.push(x);
        }
        while(pq.size() > 1){
            int t = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            if(t==s) continue;
            else pq.push(t-s);
        }
        if(pq.size()==0) return 0;
        return pq.top();
    }
};