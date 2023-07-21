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
        int n, m, h;
        cin >> n >> m >> h;
        int ans = 1;
        int one = 0; 
        ll two = 0;
        for(int i = 0; i < n; i++){
            vector<int> curr(m);
            for(int j = 0; j < m; j++){
                cin >> curr[j];
            }
            sort(curr.begin(), curr.end());
            ll penalty = 0, sum = 0;
            int probs = 0;

            for(int j = 0; j < m; j++){
                if(sum + curr[j] > h) break;
                sum += curr[j];
                penalty += sum;
                probs++;
            }
            if(i){
                if(probs > one) ans++;
                else if(probs == one && penalty < two) ans++;
            }
            else{
                one = probs;
                two = penalty;
            }
        }
        cout << ans << endl;
    }
    return 0;
}