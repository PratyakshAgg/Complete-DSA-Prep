class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int n = str.size();
        for(int i = n/2; i >= 1; i--){
            if(n%i != 0) continue;
            string x = str.substr(0, i);
            int times = n / i;
            string newstr = "";
            while(times--){
                newstr += x;
            }
            if(newstr == str){
                return true;
            }
        }
        return false;
    }
};