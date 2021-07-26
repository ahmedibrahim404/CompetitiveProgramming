#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=100+3;
int n, m, k, ns[MAX];
ll dp[MAX][MAX][MAX], cs[MAX][MAX];

ll solve(int cur=0, int pre=0, int rem=k){

    if(cur == n && rem == 0) return 0;
    if(rem < 0 || (cur==n && rem != 0)) return 1e18;

    ll &ret=dp[cur][pre][rem];
    if(ret != -1) return ret;

    if(ns[cur]==0){
        ret=1e18;
        for(int i=1;i<=m;i++) ret=min(ret, solve(cur+1, i, rem-(pre!=i)) + cs[cur][i-1]);
    } else {
        if(ns[cur] == pre) ret = solve(cur+1, pre, rem);
        else ret = solve(cur+1, ns[cur], rem-1);
    }

    return ret;

}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n;i++){
        scanf("%d",&ns[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&cs[i][j]);
        }
    }

    ll ans=solve();
    if(ans==1e18) printf("-1");
    else printf("%lld", ans);
    return 0;
}
