class Solution {
public:
    bool isPred(string &prev, string &curr){
        int m = prev.length();
        int n = curr.length();
        if(m >= n || n-m != 1) return false;
        int i = 0, j = 0;
        while(i < m && j < n){
            if(prev[i] == curr[j]) i++;
            j++;
        }
        return i == m;
    }

    static bool comparator(string &word1, string &word2){
        return word1.length() < word2.length();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comparator);
        vector<int> dp(n, 1);
        int maxL = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(isPred(words[j], words[i])){
                    dp[i] = max(dp[i], dp[j]+1);
                    maxL = max(maxL, dp[i]);
                }
            }
        }
        return maxL;
    }
};