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

bool check(ll n, ll m){
    if(m==n) return true;
    if(m > n || n%3!=0) return false;
    return (check(n/3, m) || check(n-n/3, m));
}

void solve(){
    ll n, m;
    cin >> n >> m;
    check(n, m)==true ? cout << "YES" << endl : cout << "NO" << endl;
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