class Solution {
public:
    int solve(string &s, int &k, char c){
        int i = 0, ans = 0, cnt = 0;
        int n = s.length();

        for(int j = 0; j < n ;j++){
            if(s[j] == c) cnt++;

            while(cnt > k){
                if(s[i] == c) cnt--;
                i++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(solve(answerKey, k, 'F'), solve(answerKey, k, 'T'));
    }
};