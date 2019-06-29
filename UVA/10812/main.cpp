#include <iostream>

using namespace std;

long long t, s, d;
int main(){

    scanf("%d", &t);

    while(t--){
        scanf("%lld %lld", &s, &d);
        if(d > s || (s+d)%2 == 1){
            printf("impossible\n");
            continue;
        }

        long long v1=(s+d)/2;
        long long v2=s-v1;

        printf("%lld %lld\n", v1, v2);

    }

    return 0;
}
