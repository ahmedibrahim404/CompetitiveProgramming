#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD=10000007;

long long pow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll n, k;
int main(){
    // 6 10 15
    while(scanf("%lld%lld",&n,&k) && (n|k)){
        ll ans = 2*pow(n-1, k) % MOD;
        ans %= MOD;
        ans += pow(n, k) % MOD;
        ans %= MOD;
        ans += 2 * pow(n-1, n-1)%MOD;
        ans %= MOD;
        ans += pow(n, n) % MOD;
        ans %= MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
