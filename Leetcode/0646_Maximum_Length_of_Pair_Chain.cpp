class Solution {
public:
    bool static cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), cmp);

        int ans = 1;
        auto last = pairs[0];
        for(int i = 1; i < n; i++){
            if(pairs[i][0] > last[1]){
                last = pairs[i];
                ans++;
            }
        }
        return ans;
    }
};