class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int x = purchaseAmount%10;
        if(x < 5){
            purchaseAmount -= x;
            return (100-purchaseAmount);
        }
        else{
            purchaseAmount += (10-x);
            return (100-purchaseAmount);
        }
    }
};