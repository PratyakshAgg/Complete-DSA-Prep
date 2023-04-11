class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto it : mp){
            pq.push({-it.second, it.first});
        }
        while(!pq.empty()){
            int x = abs(pq.top().first);
            for(int i = 0; i < x; i++){
                ans.push_back(pq.top().second);
            }
            pq.pop();
        }
        return ans;
    }
};