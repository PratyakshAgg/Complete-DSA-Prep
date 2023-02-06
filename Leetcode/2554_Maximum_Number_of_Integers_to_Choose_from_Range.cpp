class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int sum = 0, cnt = 0;
        for(int i = 1; i <= n; i++){
            if(find(banned.begin(), banned.end(), i) != banned.end()){
                continue;
            }
            else{
                sum += i;
                if(sum > maxSum) break;
                cnt++;
            }
        }
        return cnt;
    }
};