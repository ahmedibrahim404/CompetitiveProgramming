#include <iostream>
using namespace std;
typedef long long ll;
int n, m;
ll as[21], bs[21], tot, h, rate;

ll solve(int idx=0, ll cur=0){

    if(cur>=rate){
        return 0;
    }

    if(idx==n) return 1e18;
    return min( solve(idx+1, cur), solve(idx+1, cur+as[idx])+bs[idx] );

}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld%lld",&as[i],&bs[i]);
    scanf("%d",&m);
    for(int ts=1;ts<=m;ts++){

        scanf("%lld%lld", &tot, &h);
        rate=(tot+(h-1))/h;
        ll ans=solve();
        if(ans > 2*1e10) printf("Case %d: IMPOSSIBLE\n",ts);
        else printf("Case %d: %lld\n",ts, ans);

    }
    return 0;
}
