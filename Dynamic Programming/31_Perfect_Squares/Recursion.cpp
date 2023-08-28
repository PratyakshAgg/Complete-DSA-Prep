class Solution {
public:
    int solve(int n){
        if(n == 0) return 0;
        int ans = n;
        for(int i = 1; i*i <= n; i++){
            int tmp = i*i;
            ans = min(ans, 1 + solve(n-tmp));
        }
        return ans;
    }

    int numSquares(int n) {
        return solve(n);
    }
};