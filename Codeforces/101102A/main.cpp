#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=150+3;
const int W=15000+3;
const int MOD=1e9+7;

ll d1[MAX][W];
ll d2[MAX][W];
int n, m, k, w;
int ns[MAX], ms[MAX];

ll nf(int idx=0, int sum=0){
    if(idx==n)return sum==0;
    ll &ret=d1[idx][sum];
    if(~ret)return ret;
    ret=0;
    if(ns[idx] <= sum) ret += nf(idx+1, sum-ns[idx])%MOD;
    ret+=nf(idx+1, sum)%MOD;
    return ret%MOD;
}
ll mf(int idx=0, int sum=0){
    if(idx==m)return !sum;
    ll &ret=d2[idx][sum];
    if(~ret )return ret;
    ret=0;
    if(ms[idx] <= sum) ret += mf(idx+1, sum-ms[idx])%MOD;
    ret += mf(idx+1, sum)%MOD;
    return ret%MOD;
}

int t;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&m,&k,&w);
        for(int i=0;i<n;i++) scanf("%d",&ns[i]);
        for(int i=0;i<m;i++) scanf("%d",&ms[i]);
        memset(d1, -1, sizeof d1);
        memset(d2, -1, sizeof d2);
        ll ans=0;
        for(int i=0;i<=w;i++){
            int fir=i, sec=w-i;
            if(abs(sec-fir) <= k){
                ans += 1LL*nf(0, fir)%MOD*mf(0,sec)%MOD;
            }

        }

        printf("%lld\n", ans%MOD);

    }

    return 0;
}
