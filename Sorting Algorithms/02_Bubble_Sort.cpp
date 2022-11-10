#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
    int i, j;
    bool swapped;
    for(i = 0; i < n; i++){
        swapped = false;
        for(j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout <<" "<< arr[i];
}

int main() {
    int arr[] = {5, 3, 1, 9, 8, 2, 4, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "Sorted Array: \n";
    printArray(arr, n);
    return 0;
}