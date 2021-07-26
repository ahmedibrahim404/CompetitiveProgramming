#include<bits/stdc++.h>

using namespace std;
int n, cnt[70+3], no, dp[4900+9][70+3], MOD=1e9+7;

int solve(int has, int cur){
    if(has == 1) return 1;
    if(cur == 71) return 0;

    int &ret=dp[has][cur];
    if(ret != -1) return ret;

    ret=0;
    if(has%cur==0) ret+=(cnt[cur]*solve(has/cur, cur+1))%MOD;
    ret += solve(has, cur+1)%MOD;
    return ret%MOD;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&no);
        cnt[no]++;
    }
    int ans=0;
    for(int i=1;i<=70;i++){
        memset(dp, -1, sizeof(dp));
        int to=i*i;
        ans += solve(to, 1)%MOD;
    }
    ans %=MOD;
    printf("%d", ans);
    return 0;
}
