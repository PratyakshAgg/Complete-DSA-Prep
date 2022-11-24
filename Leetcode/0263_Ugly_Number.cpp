class Solution {
public:
    bool isUgly(int n) {
        for(int i = 2; i < 6 && n; i++){
            if(i==4) continue;
            while(n%i==0)
                n/=i;
        }
        return n==1;
    }
};