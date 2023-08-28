class Solution {
public:
    unordered_map<int, int> mp;
    bool solve(vector<int> &stones, int curr_idx, int prevJump, vector<vector<int>> &dp){
        if(curr_idx == stones.size()-1) return true;

        if(dp[curr_idx][prevJump] != -1) return dp[curr_idx][prevJump];

        bool res = false;

        for(int i = prevJump-1; i <= prevJump+1; i++){
            if(i > 0){
                int next_stone = stones[curr_idx] + i;

                if(mp.find(next_stone) != mp.end()){
                    res = res || solve(stones, mp[next_stone], i, dp);
                }
            }
        }
        return dp[curr_idx][prevJump] = res;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1] != 1) return false;

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        for(int i = 0; i < n; i++){
            mp[stones[i]] = i;
        }

        return solve(stones, 0, 0, dp);
    }
};