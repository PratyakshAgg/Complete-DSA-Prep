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

vector<ll> cnt;
vector<vector<int>> adj;

void dfs(int v, int p){
    if (adj[v].size() == 1 && adj[v][0] == p) {
        cnt[v] = 1;
    } else {
        for (auto u : adj[v]) {
            if (u != p) {
                dfs(u, v);
                cnt[v] += cnt[u];
            }
        }
    }
}

void solve() {
    int n, q;
    cin >> n;
    adj.assign(n, vector<int>());
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cnt.assign(n, 0);
    dfs(0, -1);

    cin >> q;
    while(q--){
        int c, k;
        cin >> c >> k;
        c--;
        k--;

        ll res = cnt[c] * cnt[k];
        cout << res << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}