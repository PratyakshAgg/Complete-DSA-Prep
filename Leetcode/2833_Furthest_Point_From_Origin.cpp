class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cntL = 0;
        int cntR = 0;
        int cnt_ = 0;
        for(int i = 0; i < moves.size(); i++){
            if(moves[i] == 'L') cntL++;
            else if(moves[i] == 'R') cntR++;
            else cnt_++;
        }
        if(cntL > cntR){
            return cntL+cnt_-cntR;
        }
        else{
            return cntR+cnt_-cntL;
        }
    }
};