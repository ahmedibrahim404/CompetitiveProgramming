#include<bits/stdc++.h>
using namespace std;
const int MAX=200000+3;
string s;
int n;
int dp[MAX][3];
int solve(int idx, int mod){

    if(idx==n) return 0;
    int &ret=dp[idx][mod];
    if(~ret) return ret;
    ret=0;

    int nMod=((s[idx]-'0')+mod)%3;
    if(idx+1 < n && s[idx+1]-'0'==0) ret=max(ret, (nMod==0?1:0)+1+solve(idx+2, 0));
    else ret=max(ret, (nMod==0?1:0)+solve(idx+1, 0));
    ret=max(ret, solve(idx+1, nMod));

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin >> s;
    n=s.length();
    cout << solve(0, 0) << endl;

    return 0;
}
