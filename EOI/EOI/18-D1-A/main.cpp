#include <iostream>
using namespace std;
typedef long long ll;

ll l, r;

ll gcd(ll a, ll b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main(){
    scanf("%lld %lld", &l, &r);

    for(ll i=l;i<=r;i++){
        for(ll j=i+1;j<=r;j++){
            for(ll k=j+1;k<=r;k++){
                if(gcd(i, j) == 1 && gcd(j, k) == 1 && gcd(i, k) != 1) return printf("%lld %lld %lld\n", i, j, k), 0;
            }
        }
    }

    printf("-1");

    return 0;
}
