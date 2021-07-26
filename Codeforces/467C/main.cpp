#include<bits/stdc++.h>
using namespace std;
unsigned int MAX=5000+3;
typedef long long ll;
ll dp[5005][5005];
ll ns[5000+3];
int n, m, k;

ll solve(int cur=1, int rem=k){
    if(cur+m-1 > n) return 0;
    if(rem == 0) return 0;

    ll &ret=dp[cur][rem];
    if(ret!=-1) return ret;

    ret=(ns[cur+m-1]-ns[cur-1])+solve(cur+m, rem-1);
    ret=max(ret, solve(cur+1, rem));
    return ret;
}

int main(){
    scanf("%d %d %d",&n,&m,&k);
    memset(dp, -1, sizeof(dp));
    ns[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&ns[i]);
        ns[i] += 1LL*ns[i-1];
    }

    printf("%lld", solve());

    return 0;
}

