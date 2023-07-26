class Solution {
public:
    bool isPossible(vector<int> &dist, double hour, int speed){
        double time = 0;
        for(int i = 0; i < dist.size()-1; i++){
            time += ceil((double)dist[i] / speed);
        }
        time += ((double)dist.back()) / speed;
        return time <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(hour <= double(n-1)) return -1;
        int left = 1, right = 1e9;
        while(left < right){
            int mid = left + (right-left)/2;
            if(isPossible(dist, hour, mid)) right = mid;
            else left = mid + 1;
        }
        return right;
    }
};