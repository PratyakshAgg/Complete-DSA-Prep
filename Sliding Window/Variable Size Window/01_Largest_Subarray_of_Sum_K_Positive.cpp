class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        // Complete the function
        int i = 0;
        int ans = 0;
        int sum = 0;
        
        for(int j = 0; j < n; j++){
            sum += arr[j];
            if(sum == k){
                ans = max(ans, j-i+1);
            }
            else if(sum > k){
                while(sum > k){
                    sum -= arr[i];
                    i++;
                }
            }
        }
        return ans;
    } 

};