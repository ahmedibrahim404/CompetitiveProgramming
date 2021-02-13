#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=250+5;
int n, m;ll dp[MAX][51];int ms[51];

ll solve(int cur, int coin){
    if(coin == m) return cur == 0;
    ll &ret=dp[cur][coin];
    if(~ret) return ret;
    ret=0;
    int rem=0;
    while(true){
        if(cur-rem < 0) break;
        ret += solve(cur-rem, coin+1);
        rem += ms[coin];
    }
    return ret;
}

int main(){
    scanf("%d%d",&n,&m);
    memset(dp, -1, sizeof dp);
    for(int i=0;i<m;i++) scanf("%d",&ms[i]);
    sort(ms, ms+m);
    printf("%lld\n", solve(n, 0));
    return 0;

}
