class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        findSubsets(0, nums, ans, ds);
        return ans;
    }

    void findSubsets(int ind, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        if(ind == arr.size()){
            ans.push_back(ds);
            return;
        }

        ds.push_back(arr[ind]);
        findSubsets(ind+1, arr, ans, ds);
        ds.pop_back();
        findSubsets(ind+1, arr, ans, ds);

    }
};