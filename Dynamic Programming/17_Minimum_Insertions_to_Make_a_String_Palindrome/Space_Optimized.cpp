class Solution {
public:
    int minInsertions(string s) {
        string s1 = s;
        int n = s.size();
        reverse(s.begin(), s.end());
        string s2 = s;
        vector<int> prev(n+1, 0), curr(n+1, 0);

        for(int j = 0; j <= n; j++) prev[j] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }

        return n-prev[n];
    }
};