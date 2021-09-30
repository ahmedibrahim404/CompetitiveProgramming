#include <iostream>

using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
const int N = 2e5+6;
long long binpow(long long a, long long b) {
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

int main(){
    int t;
    cin >> t;

    ll fact[N];
    fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i] = (fact[i-1]%MOD*i)%MOD;
        fact[i] %= MOD;
    }

    while(t--){
        int n;
        cin >> n;
        ll ans = (fact[2*n] * binpow(2, MOD-2))%MOD;
        cout << ans << "\n";
    }
    return 0;
}
