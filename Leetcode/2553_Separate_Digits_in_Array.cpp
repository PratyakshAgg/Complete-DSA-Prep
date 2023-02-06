class Solution {
public:
    vector<int> separateDigits(vector<int>& v) {
        int n = v.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            vector<int> temp;
            while(v[i]){
                int x = v[i]%10;
                temp.push_back(x);
                v[i]/=10;
            }
            reverse(temp.begin(), temp.end());
            for(int j = 0; j < temp.size(); j++){
                ans.push_back(temp[j]);
            }
        }
        return ans;
    }
};