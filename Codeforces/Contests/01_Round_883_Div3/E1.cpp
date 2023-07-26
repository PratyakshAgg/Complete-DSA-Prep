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
 
bool solve(int n){
    for(int i = 2; i <= sqrt(n); i++){
        int temp = 1;
        while(temp <= n){
            if(temp == n){
                return true;
            }
            temp = temp*i + 1;
        }
    }
    return false;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(solve(n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    retur