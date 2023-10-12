class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = people.size();
        int m = flowers.size();
        vector<int> start_time(m);
        vector<int> end_time(m);

        for(int i = 0; i < m; i++){
            start_time[i] = flowers[i][0];
            end_time[i] = flowers[i][1];
        }

        sort(start_time.begin(), start_time.end());
        sort(end_time.begin(), end_time.end());

        vector<int> res(n);

        for(int i = 0; i < n; i++){
            int time = people[i];
            int bloomed = upper_bound(start_time.begin(), start_time.end(), time) - start_time.begin();
            int died = lower_bound(end_time.begin(), end_time.end(), time) - end_time.begin();
            res[i] = bloomed - died;
        }
        return res;
    }
};