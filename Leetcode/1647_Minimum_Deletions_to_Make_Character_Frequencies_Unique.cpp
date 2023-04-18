class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26);
        int ans = 0;
        for(auto a : s){
            v[a-'a']++;
        }
        sort(v.begin(), v.end(), greater<int>());
        int mx = v[0];
        for(auto a : v){
            if(a > mx){
                if(mx > 0) ans += a - mx;
                else ans += a;
            }
            mx = min(mx-1, a-1);
        }
        return ans;
    }
};