#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define MOD 1e9+7
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)

void solve(int ind, int arr[], vector<int> &ds, int n){
    if(ind >= n){
        for(auto it : ds){
            cout << it << " ";
        }
        if(ds.size()==0){
            cout << "{}";
        }
        cout << endl;
        return;
    }

    ds.push_back(arr[ind]);
    solve(ind + 1, arr, ds, n);
    ds.pop_back();
    solve(ind + 1, arr, ds, n);

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[] = {3, 1, 2};
    int n = 3;
    vector<int> ds;
    solve(0, arr, ds, n);
    return 0;
}