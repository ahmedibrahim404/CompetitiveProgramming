#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const int MAX=100+3;
ll dp[MAX][2];
int n, k, d;

ll solve(int sum, bool is){
    if(sum==0){
        if(is) return 1;
        return 0;
    }

    ll &ret=dp[sum][is];
    if(~ret) return ret%MOD;
    ret=0;

    for(int i=1;i<=k;i++){
        if(sum-i>=0){
            ret += solve(sum-i, i>=d?1:is);
        }
        ret %= MOD;

    }


    return ret%MOD;

}

int main(){

    scanf("%d%d%d",&n,&k,&d);
    memset(dp, -1, sizeof dp);
    printf("%lld\n", solve(n, 0));

    return 0;
}
