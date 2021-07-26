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
ll a, b;


int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&a,&b);
        printf("%lld\n", pow(a, b, 10));
    }
    return 0;
}
