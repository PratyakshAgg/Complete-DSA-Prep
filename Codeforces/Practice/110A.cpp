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
    long long int n;
    int lucky = 0;
    cin >> n;
    while(n){
        if(n%10 == 7 || n%10 == 4)
            lucky++;
        n/=10;

    }
    if(lucky==7 || lucky==4) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}