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
    int x = 0, y = 0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
        if(s[i]=='L') x--;
        else if(s[i]=='R') x++;
        else if(s[i]=='U') y++;
        else y--;

        if(x==1 && y==1){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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