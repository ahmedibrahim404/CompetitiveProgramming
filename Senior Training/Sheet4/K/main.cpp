#include <iostream>

using namespace std;
typedef long long ll;

long long pow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int t;
ll a, b, c;


int main(){
    while(scanf("%lld%lld%lld",&a,&b,&c) == 3){
        printf("%lld\n", pow(a, b, c));
    }
    return 0;
}
