#include <iostream>

using namespace std;

long long a, b, k;
int T;
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%lld %lld %lld", &a, &b, &k);
        long long ans = (a-b)*(k/2);
        if(k%2==1)
            ans += a;
        printf("%lld\n", ans );
    }
    return 0;
}
