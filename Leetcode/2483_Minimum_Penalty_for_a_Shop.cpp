class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int pen = count(customers.begin(), customers.end(), 'Y');
        int penalty = pen;
        int ind = 0;
        for(int i = 1; i <= n; i++){
            if(customers[i-1] == 'Y'){
                pen--;
            }
            else pen++;

            if(pen < penalty){
                penalty = min(pen, penalty);
                ind = i;
            }
        }
        return ind;
    }
};