#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne];
    auto *rightArray = new int[subArrayTwo];

    for(auto i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[left+i];
    for(auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[mid+1+j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while(indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if(leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]){
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else{
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while(indexOfSubArrayOne < subArrayOne){
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfMergedArray++;
        indexOfSubArrayOne++;
    }

    while(indexOfSubArrayTwo < subArrayTwo){
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfMergedArray++;
        indexOfSubArrayTwo++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int array[], int const begin, int const end){
    if(begin >= end) return;
    auto mid = begin + (end-begin)/2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void printArray(int arr[], int size)
{
    for(auto i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i]; 
    }
    cout << "Original array is: \n";
    printArray(arr, n);

    mergeSort(arr, 0, n-1);

    cout << "\nSorted array is: \n";
    printArray(arr, n);
    return 0;
}