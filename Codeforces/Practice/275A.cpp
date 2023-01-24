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
    int a[5][5] = {0};
    for(int i = 1; i < 4; i++){
        for(int j = 1; j < 4; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i < 4; i++){
        for(int j = 1; j < 4; j++){
            int sum = a[i][j] + a[i-1][j] + a[i+1][j] + a[i][j-1] + a[i][j+1];
            if(sum%2 == 0) cout << "1";
            else cout << "0";
        }
        cout << endl;
    }
    return 0;
}