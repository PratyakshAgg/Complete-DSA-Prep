#include <bits/stdc++.h> 
bool isPerfectSquare(long long n) {
    long long int s = 0;
    long long int e = 1e9;
    while(s <= e){
        long long int m = s + (e-s)/2;
        if(m*m == n) return true;
        else if(m*m < n) s = m + 1;
        else e = m - 1;
    }
    return false;
}