#include <iostream>

using namespace std;
typedef long long ll;

int main(){
    ll a, b;

    while(scanf("%lld %lld", &a, &b) == 2) {
        printf("%lld\n", (a^b));
    }
    return 0;
}
