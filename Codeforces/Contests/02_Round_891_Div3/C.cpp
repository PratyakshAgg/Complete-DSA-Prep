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
    int n;
    cin >> n;
    int m = n*(n-1)/2;
    vector<int> b(m);
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    for(int i = 0; i < m; i+=--n){
        cout << b[i] << " ";
    }
    cout << "1000000000" << endl;
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