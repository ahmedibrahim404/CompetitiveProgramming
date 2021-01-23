#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mx=0;

ll x=1, y=1;


ll extended(ll a, ll b){

    if(a<0){
        ll ans=extended(-a, b);
        x*= -1;
        return ans;
    }
    if(b<0){
        ll ans=extended(a, -b);
        y*= -1;
        return ans;
    }

    if(!b){
        x=1, y=0;
        return a;
    }

    ll ans=extended(b, a%b);
    ll prevx=x, prevy=y;
    x=prevy;
    y=prevx-(a/b)*x;

    return ans;

}
ll e,d;

ll ans=2e19;
ll lin(ll a, ll b, ll c){

    ll g=extended(a, b);

    if(c%g==0){
        x*=c/g, y*=c/g;
        if(x<0 && y<0){
            return g;
        }

          if(!c){
            x=x+1*b/__gcd(a, b);
            y=y-1*a/__gcd(a, b);
        }

        ans=min(ans, max(abs(e*x), abs(d*y)));

    }


    return g;

}

int main(){
    scanf("%lld%lld",&e,&d);
    if(d>e) swap(e, d);

    if(d==1){
        if(e==1){
            cout << 1;
        } else {
            cout << 2;
        }
        return 0;
    }

    lin(e, -d, 0);
    lin(e, -d, 1);
    lin(e, -d, -1);
    cout << ans << "\n";

    return 0;
}
