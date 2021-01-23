#include <iostream>

using namespace std;
typedef long long ll;
ll N, M;
ll MOD=1e9+7;
ll pow(ll n,ll m){
    if(m==1) return n;
    ll res;
    res=pow(n, m>>1);
    res = ((res%MOD)*(res%MOD))%MOD;
    if(m&1) res *= (n%MOD);
    res %= MOD;
    return res;

}

int main(){
    scanf("%lld%lld",&N,&M);
    printf("%lld", pow(N,M));
    return 0;
}
