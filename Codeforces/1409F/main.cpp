#include<bits/stdc++.h>

using namespace std;
string s, t;
int n, k;
const int MAX=200+4;
int dp[MAX][MAX][MAX];
int solve(int idx, int rem, int fs){

    if(idx==n) return 0;
    int &ret=dp[idx][rem][fs];
    if(~ret) return ret;
    ret=0;
    if(rem){

        ret=max(ret, solve(idx+1, rem-1, fs + 1) + (t[0]==t[1] ? fs : 0));
        ret=max(ret, solve(idx+1, rem-1, fs + (t[0]==t[1] ? 1 : 0)) + fs);
    }
    ret=max(ret, solve(idx+1, rem, fs+(s[idx]==t[0] ? 1 : 0)) + ( s[idx] == t[1] ? fs : 0 ));
    return ret;
}

int main(){
    cin >> n >> k;
    cin >> s >> t;
    memset(dp, -1, sizeof dp);
    cout << solve(0, k, 0) << "\n";
    return 0;
}
