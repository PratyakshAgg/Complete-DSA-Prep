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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        vector<int> v(26, 0), p(26, 0);
        for(auto x : s) v[x-'a']++;
        for(auto x : s){
            v[x-'a']--;
            p[x-'a']++;
            int curr = 0;
            for(int i = 0; i < 26; i++){
                curr += (min(1, v[i]) + min(1, p[i]));
            }
            ans = max(ans, curr);
        }
        cout << ans << endl;
    }
    return 0;
}