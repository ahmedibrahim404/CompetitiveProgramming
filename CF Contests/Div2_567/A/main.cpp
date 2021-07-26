#include <iostream>

using namespace std;

typedef long long ll;
ll x, y, z, ans=0;
int main(){
    scanf("%lld %lld %lld", &x, &y, &z);

    ans = (x/z) + (y/z);

    x%=z;
    y%=z;

    ll sec=0;
    if(x > y){
        if(y >= z-x) sec=z-x, ans++;
    } else {
        if(x >= z-y) sec=z-y, ans++;
    }


    printf("%lld %lld", ans, sec);

    return 0;
}
