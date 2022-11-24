class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findSubsets(ans, nums, ds, 0);
        return ans;
    }

    void findSubsets(vector<vector<int>> &ans, vector<int> &arr, vector<int> &ds, int ind){
        ans.push_back(ds);
        for(int i = ind; i < arr.size(); i++){
            if(i != ind && arr[i] == arr[i-1]) continue;
            ds.push_back(arr[i]);
            findSubsets(ans, arr, ds, i+1);
            ds.pop_back();
        }
    }
};