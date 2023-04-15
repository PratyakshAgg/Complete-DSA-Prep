class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int aheadNotbuy, aheadBuy, currBuy, currNotbuy;
        aheadNotbuy = aheadBuy = 0;
        for(int ind = n-1; ind >= 0; ind--){
            
            currBuy = max(-prices[ind] + aheadNotbuy, 0 + aheadBuy);
            
            currNotbuy = max(prices[ind] + aheadBuy, 0 + aheadNotbuy);
            
            aheadBuy = currBuy;
            aheadNotbuy = currNotbuy;
        }
        return aheadBuy;
    }
};