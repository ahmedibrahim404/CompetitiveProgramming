#include <iostream>

using namespace std;

int t;
long long s, a, b, c;
int main(){
    scanf("%d", &t);
    while(t--){

        scanf("%lld %lld %lld %lld", &s, &a, &b, &c);
        long long n=(s/c);
        long long ad=(n/a)*b;
        printf("%lld\n", (n+ad));

    }
    return 0;
}
