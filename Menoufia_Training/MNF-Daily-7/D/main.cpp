#include <iostream>

using namespace std;
typedef long long ll;
ll b, p, m;

ll power(ll x, ll p, ll m){
    ll res = 1;
    while(p){
        if(p&1)    res = (res * x)%m;
        x = (x * x)%m;
        p >>= 1;
    }
    return res;
}

int main(){

    while(scanf("%lld%lld%lld",&b,&p,&m)==3){
        printf("%lld\n", power((b%m),p,m));
    }

    return 0;
}
