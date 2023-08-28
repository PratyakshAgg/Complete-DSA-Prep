class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<vector<int>> prev(m+1, vector<int>(n+1, 0));
        vector<vector<int>> curr(m+1, vector<int>(n+1, 0));

        for(int i = N-1; i >= 0; i--){
            int cnt0 = count(strs[i].begin(), strs[i].end(), '0');
            int cnt1 = strs[i].size() - cnt0;
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    int notTake = curr[j][k];
                    int take = 0;
                    if(cnt0 <= j && cnt1 <= k){
                        take = 1 + curr[j-cnt0][k-cnt1];
                    }
                    prev[j][k] = max(take, notTake);
                }
            }
            curr = prev;
        }
        return curr[m][n];
    }
};