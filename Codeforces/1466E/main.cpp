#include <iostream>

using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int t, n;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ll ns[n];
        ll bts[61];
        for(int i=0;i<61;i++) bts[i]=0;
        for(int i=0;i<n;i++){
            scanf("%lld",&ns[i]);
            for(int j=0;j<=60;j++){
                if(ns[i]&(1LL<<j)) bts[j] ++;
            }
        }

        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            ll av = 0;
            for(ll j=0;j<61;j++){

                if (ns[i] & (1LL << j)) {
                    ll p = (1LL << j) % MOD;
                    av = (av + p * bts[j]) % MOD;
                }

            }


            ll ov = 0;
            for(ll j=0;j<61;j++){
                ll p=(1LL<<j)%MOD;


                if (ns[i] & (1LL << j)) {
                    ov = (ov + p * n) % MOD;
                } else {
                    ov = (ov + p * bts[j]) % MOD;
                }

            }


            ans = (ans + av * ov) % MOD;
        }

        printf("%lld\n", ans);

    }
    return 0;
}
