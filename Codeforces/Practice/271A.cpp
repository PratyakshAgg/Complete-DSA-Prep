#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define MOD 1e9+7
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(1){
        n++;
        int a = n%10;
        int b = (n/10)%10;
        int c = (n/100)%10;
        int d = (n/1000)%10;
        if(a != b && b != c && c != d && d != a && a != c && b != d){
            cout << n << endl;
            break;
        }
    }
    return 0;
}