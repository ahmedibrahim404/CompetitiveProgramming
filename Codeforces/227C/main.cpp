#include <iostream>

using namespace std;
typedef long long ll;

ll n, m;

inline ll power(ll x, ll p, ll m){
    ll res = 1;
    while(p){
        if(p & 1)
            res = ((res % m) * (x % m)) % m;
        x = ((x % m) * (x % m)) % m;
        p >>= 1;
    }
    return res % m;
}

int main(){

    scanf("%lld %lld", &n, &m);

    printf("%lld", (power(3, n, m)-1+m)%m);

    return 0;
}
