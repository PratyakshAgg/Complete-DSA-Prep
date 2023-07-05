class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> l;
        int i = 0;
        int n = nums.size();
        vector<int> ans;

        for(int j = 0; j < n; j++){
            while(l.back() < nums[j] && !l.empty()){
                l.pop_back();
            }
            l.push_back(nums[j]);

            if(j-i+1 == k){
                ans.push_back(l.front());

                if(l.front() == nums[i]){
                    l.pop_front();
                }
                i++;
            }
        }

        return ans;
    }
};