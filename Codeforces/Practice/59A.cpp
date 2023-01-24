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
    string s;
    cin >> s;
    int ii = 0, j = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z') ii++;
        else j++;
    }
    if(ii >= j){
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout << s << endl;
    }
    else{
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        cout << s << endl;
    }
    return 0;
}