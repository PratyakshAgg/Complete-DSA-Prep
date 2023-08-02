#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define MOD 1e9+7
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)

bool solve(int ind, int arr[], vector<int> &ds, int n, int s, int sum){
    if(ind >= n){
        if(s == sum){
            for(auto it : ds){
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        else return false;
    }

    ds.push_back(arr[ind]);
    s+=arr[ind];
    if(solve(ind + 1, arr, ds, n, s, sum)==true){
        return true;
    }
    s-=arr[ind];
    ds.pop_back();
    if(solve(ind + 1, arr, ds, n, s, sum)==true) return true;

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    solve(0, arr, ds, n, 0, sum);
    return 0;
}