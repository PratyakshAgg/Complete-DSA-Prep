#include <bits/stdc++.h> 

int f(int i, int j, string &text1, string &text2, vector<vector<int>> &dp){
    if(i == 0 || j == 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(text1[i-1] == text2[j-1]) return dp[i][j] = 1 + f(i-1, j-1, text1, text2, dp);

    return dp[i][j] = max(f(i-1, j, text1, text2, dp), f(i, j-1, text1, text2, dp));
}

int canYouMake(string &str, string &ptr)
{
    int n = str.length();
    int m = ptr.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    int x = f(n, m, str, ptr, dp);
    return n + m - 2*x;
}

