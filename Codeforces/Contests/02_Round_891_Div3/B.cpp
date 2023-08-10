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

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int y = -1;
    for(int i = n-1; i >= 0; i--){
        if(s[i] < '5') continue;
        if(s[i] == ':'){
            s[i] = '0';
            if(i-1 == -1){
                s = '1' + s;;
                break;
            } 
            s[i-1]++;
        }
        else{
            y = i;
            if(i-1 == -1){
                s = '1' + s;
                n++;
                y++;
                break;
            } 
            else{
                s[i-1]++;
            }
        }
    }
    if(y==-1){
        cout << s << endl;
        return;
    }
    for(int i = y; i < n+1; i++){
        s[i] = '0';
    }
    cout << s << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}