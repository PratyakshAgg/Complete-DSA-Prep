class Solution {
public:
    bool winnerOfGame(string colors) {
        int cnt_a = 0, cnt_b = 0;
        for(int i = 1; i < colors.size()-1; i++){
            if(colors[i] == 'A' && colors[i-1] == 'A' && colors[i+1] == 'A') cnt_a++;
            if(colors[i] == 'B' && colors[i-1] == 'B' && colors[i+1] == 'B') cnt_b++;
        }
        return cnt_a > cnt_b;
    }
};