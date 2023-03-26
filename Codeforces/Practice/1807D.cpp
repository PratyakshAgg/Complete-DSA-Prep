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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, q;
        ll sum = 0;
        cin >> n >> q;
        vector<ll> v(n+1);
        vector<ll> pref(n+1);
        pref[0] = 0;
        for(int i = 1; i <= n; i++){
            cin >> v[i];
            sum += v[i];
            pref[i] = pref[i-1];
            pref[i] += v[i];
        }
        while(q--){
            ll l, r, k;
            cin >> l >> r >> k;
            long long ans = pref[n] - (pref[r]-pref[l-1]) + k*(r-l+1);
            if(ans%2) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}