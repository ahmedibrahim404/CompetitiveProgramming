#include <iostream>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(!b) return a;
    return gcd(b, a%b);
}


int main(){
    freopen("gcd.in", "r", stdin);

    int t;
    scanf("%d",&t);
    ll g=-1;
    while(t--){
        ll a, b;
        scanf("%lld%lld",&a,&b);
        if(g == -1){
            if(a == b) g=a;
            else g=1;
        } else {
            if(a == b) g = gcd(g, a);
            else g=1;
        }
        printf("%lld\n", g);
    }

   return 0;
}
