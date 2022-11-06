#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define MOD 1e9+7
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)

void solve() {
    char g[8][8];
	set<int> r;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> g[i][j];
			if (g[i][j] == 'R') {r.insert(i);}
		}
	}
	for (int i : r) {
	    bool ok = true;
	    for (int j = 0; j < 8; j++) {
	        if (g[i][j] != 'R') {ok = false; break;}
	    }
	    if (ok) {cout << "R\n"; return;}
	}
	cout << "B\n";
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