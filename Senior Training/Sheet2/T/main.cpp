#include<bits/stdc++.h>
using namespace std;

// 0 , 4, 8, 14, 20
typedef long long ll;

int typ[26], n;
char str[100+5];
ll dp[100+5][5][2][2];
ll solve(int idx, int seq, bool prev, bool ct){
    if(seq > 2) return 0LL;
    if(idx==n) return 1LL * ct;
    ll &ret=dp[idx][seq][prev][ct];
    if(~ret) return ret;
    ret=0;
    if(str[idx] == '_'){
        for(int i=0;i<26;i++){
            ret += solve(idx+1, typ[i] == prev ? seq + 1 : 1, typ[i] == prev ? prev : !prev, i == 11 ? 1 : ct);
        }
    } else {
        int ch=str[idx]-'A';
        ret += solve(idx+1, typ[ch] == prev ? seq + 1 : 1, typ[ch] == prev ? prev : typ[ch], ch == 11 ? 1 : ct );
    }

    return ret;

}

int main(){
    for(int i=0;i<26;i++) typ[i]=0;
    memset(dp, -1, sizeof dp);
    typ[0]=typ[4]=typ[8]=typ[14]=typ[20]=1;
    scanf("%s", str);
    n=strlen(str);
    printf("%lld\n", solve(0, 0, 0, 0));

    return 0;
}
