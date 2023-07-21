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
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string s2 = s;
    reverse(s2.begin(), s2.end());
    int cnt1, cnt2;
    for(int i = 0; i < n; i++){
        if(s[i] != t[i]) cnt1++;
        if(s[i] != t[n-i-1]) cnt2++;
    }
    if(s==t){
        cout << 0 << endl;
        return;
    }
    else if(s2 == t){
        cout << 2 << endl;
        return;
    }
    else if(cnt1 < cnt2){
        if(cnt1%2) cout << cnt1*2-1 << endl;
        else cout << cnt1*2 << endl;
    }
    else if(cnt1 == cnt2){
        cout << cnt1*2-1 << endl;
    }
    else if(cnt2 < cnt1){
        if(cnt2%2) cout << cnt2*2 << endl;
        else cout << cnt2*2-1 << endl;
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