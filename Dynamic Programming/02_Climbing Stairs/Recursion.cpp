class Solution {
public:
    int climbStairs(int n) {
        return solve(n, 0);
    }

    int solve(int n, int i){
        if(i == n) return 1;
        if(i > n) return 0;
        int x = solve(n, i+1);
        int y = solve(n, i+2);
        return x + y;
    }
};