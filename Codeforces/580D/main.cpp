#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int getBit(int mask, int idx){
    return (mask>>idx)&1;
}

int setBit1(int mask, int idx){
    return mask|(1<<idx);
}

int n, m, k;
ll ns[19];
ll ex[20][20];
ll dp[1<<19][20];

ll solve(int mask, int prev, int took){

    if(took==m) return 0;

    ll &ret=dp[mask][prev];
    if(~ret) return ret;
    ret=0;
    for(int i=0;i<n;i++){
        if(getBit(mask, i)) continue;
        int nmask=mask;
        nmask=setBit1(nmask, i);
        ret=max(ret, solve(nmask, i,took+1)+ns[i]+ex[i][prev]);
    }

    return ret;

}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    memset(ex, 0, sizeof ex);
    memset(dp, -1, sizeof dp);
    for(int i=0;i<n;i++) {
        scanf("%lld",&ns[i]);
    }
    for(int i=0;i<k;i++){
        int a, b;
        ll c;
        scanf("%d%d%lld",&a,&b,&c);
        a--, b--;
        ex[a][b]=c;
    }

    printf("%lld\n", solve(0, 19, 0));

    return 0;
}
