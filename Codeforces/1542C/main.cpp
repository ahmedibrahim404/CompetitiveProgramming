#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}

int main(){

    int t;ll n;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        ll l=1;ll ans=0;
        for(ll i=2;i<=50;i++){
            ll fir = n/(1LL*l);
            l = lcm(l, i);
            ll sec=n/(1LL*l);
            ans += (i * (fir - sec)) % MOD;
            ans %= MOD;
        }
        printf("%lld\n", ans);

    }

    return 0;
}
