#include<bits/stdc++.h>

using namespace std;
const int MAX=5000+3;
int dp[MAX][MAX];
int n;
char str[MAX];
const int OO = 2e9;
int solve(int l, int r){
    if(l >= r) return 0;
    int &ret=dp[l][r];
    if(~ret) return ret;
    if(str[l] == str[r]) return ret=solve(l+1, r-1);
    return ret=min(1+ solve(l+1, r), 1 + solve(l, r-1));
}

int main(){
    scanf("%d%s", &n, str);
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(0, n-1));
    return 0;
}
