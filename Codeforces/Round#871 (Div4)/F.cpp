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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n+1, 0);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        cnt[u]++;
        cnt[v]++;
    }
    unordered_map<int, int> mp;
    for(int i = 1; i <= n; i++){
        mp[cnt[i]]++;
    }
    vector<int> v;
    for(auto p : mp){
        v.pb(p.second);
    }
    sort(v.begin(), v.end());
    if(v.size()==3){
        cout << v[1] << ' ' << v[2] / v[1] << endl;
    }
    else cout << v[0] - 1 << ' ' << v[1] / (v[0]-1) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}