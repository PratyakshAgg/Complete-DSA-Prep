
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
 
string solve(vector<vector<char>> grid){
    for(int i = 0; i < 3; i++){
        if(grid[i][0] == 'X' && grid[i][1] == 'X' && grid[i][2] == 'X') return "X";
        if(grid[i][0] == 'O' && grid[i][1] == 'O' && grid[i][2] == 'O') return "O";
        if(grid[i][0] == '+' && grid[i][1] == '+' && grid[i][2] == '+') return "+";
 
        if(grid[0][i] == 'X' && grid[1][i] == 'X' && grid[2][i] == 'X') return "X";
        if(grid[0][i] == 'O' && grid[1][i] == 'O' && grid[2][i] == 'O') return "O";
        if(grid[0][i] == '+' && grid[1][i] == '+' && grid[2][i] == '+') return "+";
    }
    if (grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X')return "X";
    if (grid[0][2] == 'X' && grid[1][1] == 'X' && grid[2][0] == 'X')return "X";
    if (grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O')return "O";
    if (grid[0][2] == 'O' && grid[1][1] == 'O' && grid[2][0] == 'O')return "O";
    if (grid[0][0] == '+' && grid[1][1] == '+' && grid[2][2] == '+')return "+";
    if (grid[0][2] == '+' && grid[1][1] == '+' && grid[2][0] == '+')return "+";
 
    return "DRAW";
 
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        vector<vector<char>> grid;
        string ans;
        for(int i = 0; i < 3; i++){
            vector<char> temp(3);
            cin >> temp[0] >> temp[1] >> temp[2];
            grid.push_back(temp);
        }
 
        ans = solve(grid);
        cout << ans << endl;
    }
    return 0;
}