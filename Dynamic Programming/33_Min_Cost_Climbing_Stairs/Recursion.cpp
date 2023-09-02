class Solution {
public:
    int solve(int ind, vector<int> &cost){
        //Base Case 
        if(ind >= cost.size()){
            return 0;
        }

        int oneStep = cost[ind] + solve(ind+1, cost);
        int twoSteps = cost[ind] + solve(ind+2, cost);

        return min(oneStep, twoSteps);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        return min(solve(0, cost), solve(1, cost));
    }
};