#include <bits/stdc++.h> 

int partition(vector<int> &nums, int low, int high){
    int pivot = nums[low];
    int i = low;
    int j = high;
    while(i < j){
        while(nums[i] <= pivot && i <= high-1) i++;
        while(nums[j] > pivot && j >= low+1) j--;
        if(i < j) swap(nums[i], nums[j]);
    }
    swap(nums[low], nums[j]);
    return j;
}

void quickS(vector<int> &nums, int low, int high){
    if(low < high){
        int p = partition(nums, low, high);
        quickS(nums, low, p-1);
        quickS(nums, p+1, high);
    }
}

vector<int> quickSort(vector<int> nums)
{
    // Write your code here.
    quickS(nums, 0, nums.size()-1);
    return nums;
}
