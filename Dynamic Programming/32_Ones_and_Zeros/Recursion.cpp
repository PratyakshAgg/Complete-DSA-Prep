class Solution {
public:
    int solve(vector<string> &strs, int m, int n, int ind){
        // Base Case
        if(m == 0 && n == 0) return 0;
        if(ind == strs.size()){
            return 0;
        }

        int notTake = solve(strs, m, n, ind+1);

        int take = 0;
        int cnt0 = count(strs[ind].begin(), strs[ind].end(), '0');
        int cnt1 = strs[ind].size() - cnt0;
        if(cnt0 <= m && cnt1 <= n){
            take = 1 + solve(strs, m-cnt0, n-cnt1, ind+1);
        }

        return max(take, notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        return solve(strs, m, n, 0);
    }
};