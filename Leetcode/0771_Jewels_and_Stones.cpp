class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        for (int i = 0; i < jewels.size(); i++){
            ans += count(stones.begin(), stones.end(), jewels[i]);
        }
        return ans;
    }
};