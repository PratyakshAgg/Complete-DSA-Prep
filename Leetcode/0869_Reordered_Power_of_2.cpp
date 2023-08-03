class Solution {
public:
    string solve(int n){
        string tmp = to_string(n);
        sort(tmp.begin(), tmp.end());
        return tmp;
    }

    bool reorderedPowerOf2(int n) {
        string x = solve(n);
        for(int i = 0; i < 32; i++){
            if(x == solve(1 << i)) return true;
        }
        return false;
    }
};