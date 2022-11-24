#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define MOD 1e9+7
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)

int solve(int ind, int arr[], int n, int s, int sum){
    if(s > sum) return 0;
    if(ind >= n){
        if(s == sum){
            return 1;
        }
        else return 0;
    }

    s+=arr[ind];
    int l = solve(ind + 1, arr, n, s, sum);
    s-=arr[ind];
    int r = solve(ind + 1, arr, n, s, sum);

    return l + r;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    cout << solve(0, arr, n, 0, sum);
    return 0;
}