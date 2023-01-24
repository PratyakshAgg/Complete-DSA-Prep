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
    string x, y;
    cin >> x >> y;
    int n = x.size();
    for(int i = 0; i < n; i++){
        if(x[i] == y[i]) cout << '0';
        else cout << '1';
    }
}