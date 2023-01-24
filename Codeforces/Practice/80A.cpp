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

bool isPrime(int n){
    for(int i = 2; i < n; i++){
        if(n%i==0) return false; 
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int n, m;
    int x = 1;
    cin >> n >> m;
    if(!isPrime(m)) cout << "NO" << endl;
    else{
        for(int i = 0; i < 15; i++){
            if(v[i] == m && v[i-1] == n){
                cout << "YES" << endl;
                x = 0;
                break;
            }
        }
        if(x==1) cout << "NO" << endl;
    }
    return 0;
}