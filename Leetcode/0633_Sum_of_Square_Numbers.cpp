class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int left = 0, right = sqrt(c);
        while(left <= right){
            long long int ans = (left*left) + (right*right);
            if(ans < c) left++;
            else if(ans > c) right--;
            else return true;
        }
        return false;
    }
};