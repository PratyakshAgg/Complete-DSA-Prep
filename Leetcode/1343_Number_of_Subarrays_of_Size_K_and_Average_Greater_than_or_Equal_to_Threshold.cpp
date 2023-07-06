class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0, i = 0, sum = 0;

        for(int j = 0; j < arr.size(); j++){
            sum += arr[j];

            if(j-i+1 == k){
                if(sum/k >= threshold) ans++;
                sum -= arr[i];
                i++;
            }
        }
        return ans;
    }
};