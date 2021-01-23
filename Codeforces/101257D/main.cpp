#include <iostream>

using namespace std;
typedef long long ll;
ll n, x, y;

ll f(ll num){
    return max( x*num, (n-num)*y );
}

int main(){

    scanf("%lld%lld%lld",&n,&x,&y);

    ll st=0, en=n;
    while(en - st> 3){

        ll g=st+(en-st)/3, h=st+2*(en-st)/3;
        if(f(g) < f(h))
            en=h;
        else
            st=g;

    }
    ll ans=2e18;
    for(ll i=st;i<=en;i++){
        ans=min( ans, f(i) );
    }

    printf("%lld\n", ans);

    return 0;
}
