#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int t, n, k;
ll dp[1<<12][100];

int getBit(int mask, int idx){
    return (mask>>idx)&1;
}

int setBit1(int mask, int idx){
    return mask|(1<<idx);
}

ll solve(int mask=0, int invs=0){

    int cnt=__builtin_popcount(mask);
    if(cnt==n) return invs==k;

    ll &ret=dp[mask][invs];
    if(~ret) return ret;

    int bf=0;
    ret=0;
    for(int i=n;i;i--){
        if(getBit(mask, i-1)) {bf++; continue;}
        if(invs+bf>k) continue;
        ret += solve(setBit1(mask, i-1), invs+bf);
    }

    return ret;

}

int main(){
    scanf("%d",&t);
    while(t--){
        memset(dp, -1, sizeof dp);
        scanf("%d%d",&n,&k);
        printf("%d\n", solve());
    }
    return 0;
}
