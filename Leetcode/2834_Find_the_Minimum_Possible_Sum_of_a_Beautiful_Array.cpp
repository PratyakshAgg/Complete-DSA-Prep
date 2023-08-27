class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long sum = 0;
        set<int> st;
        int i = 1;
        while(n>0){
            if(st.count(i)){
                i++;
                continue;
            }
            else{
                st.insert(target-i);
                sum += i;
                n--;
                i++;
            }
        }
        return sum;
    }
};