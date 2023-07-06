class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int n = fruits.size();
        int ans = INT_MIN;
        int i = 0;
        for(int j = 0; j < n; j++){
            mp[fruits[j]]++;
            if(mp.size() <= 2){
                ans = max(ans, j-i+1);
            }
            if(mp.size() > 2){
                while(mp.size() > 2){
                    mp[fruits[i]]--;
                    if(!mp[fruits[i]]) mp.erase(fruits[i]);
                    i++;
                }
            }
        }
        return ans;
    }
};