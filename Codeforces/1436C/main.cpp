#include <iostream>

using namespace std;
typedef long long ll;
int x, n, pos;
const ll MOD=1e9+7;
ll fact[1000+3];

long long pow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res % m;
}

ll nPr(ll n, ll r){
    return (fact[n]%MOD*pow(fact[n-r], MOD-2, MOD)%MOD)%MOD;
}

int main(){

    fact[0]=1;
    for(int i=1;i<=1000;i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }

    cin >> n >> x >> pos;
    int st=0, en=n;
    int b=0, a=0;
    while(en > st){
        int mid=(st+en)/2;
        if(mid <= pos){
            st=mid+1;
            if(mid != pos) b++;
        } else en=mid, a++;
    }



    ll ans=nPr(x-1, b)%MOD;
    ans *= nPr(n-x, a)%MOD;
    ans %= MOD;
    ans *= fact[n-a-b-1];
    ans %= MOD;

    cout << ans << "\n";


    return 0;
}
