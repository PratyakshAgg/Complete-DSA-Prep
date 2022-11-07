#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define MOD 1e9+7
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        vector<int> v(1001, 0);
        int n;
        cin >> n;
        int ans = -1;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            v[x] = i;
        }
        for(int i = 1; i <= 1000; i++){
            for(int j = 1; j <= 1000; j++){
                if(v[i] && v[j] && int(__gcd(i, j))==1)
                    ans = max(ans, v[i]+v[j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}