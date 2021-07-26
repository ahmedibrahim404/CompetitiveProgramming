#include<bits/stdc++.h>

using namespace std;
int n, m, k;
int dp[71][71][71][71];
int ns[71][71];
int cur;
int solve(int row, int col, int mod, int rem){

    if(col==m){
        return solve(row+1, 0, mod, m/2);
    }

    if(row==n){
        if(mod==0) return 0;
        return -1e9;
    }

    int &ret=dp[row][col][mod][rem];
    if(ret != -1) return ret;
    ret=solve(row, col+1, mod, rem);
    if(rem) ret=max(ret, ns[row][col]+solve(row, col+1, (mod+ns[row][col])%k, rem-1));

    return ret;

}

int main(){
    cin >> n >> m >> k;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> ns[i][j];
    memset(dp, -1, sizeof dp);
    int ans=0;
    ans = solve(0, 0, 0, m/2);
    cout << ans << "\n";
    return 0;
}
