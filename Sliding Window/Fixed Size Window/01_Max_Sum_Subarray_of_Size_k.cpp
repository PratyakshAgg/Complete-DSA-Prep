class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        int i = 0;
        int j = 0;
        long sum = 0;
        long mx = INT_MIN;
        while(j < n){
            sum += arr[j];
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                mx = max(mx, sum);
                sum-=arr[i];
                i++;
                j++;
            }
        }
        return mx;
    }
};