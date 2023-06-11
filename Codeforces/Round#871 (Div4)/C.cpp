#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define ff first
#define ss second
#define u_map unordered_map
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define MOD 1e9+7
#define pb push_back
#define MP make_pair
#define f(i,a,b) for (int i = a; i <= b; i++)

void solve(){
    int n, x, y, z, temp, res;
    cin >> n;
    z = y = x = INT_MAX;
    string str;
    for(int i = 0; i < n; i++){
        cin >> temp >> str;
        if(str=="01") x = min(x, temp);
        else if(str=="10") y = min(y, temp);
        else if(str=="11") z = min(z, temp);
    }

    if(x==INT_MAX || y==INT_MAX) res = min(INT_MAX, z);
    else res = min(x+y, z);
    if(res==INT_MAX) cout << -1 << endl;
    else cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}