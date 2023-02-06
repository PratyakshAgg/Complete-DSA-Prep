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
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    int x = 0, y = 0, a = 0, b = 0;
    for(auto &i : v){
        cin >> i.first >> i.second;
        x += (i.first==1);
        y += (i.first==0);
        a += (i.second==1);
        b += (i.second==0);
    }
    cout << min(x, y) + min(a, b) << endl;
    return 0;
}