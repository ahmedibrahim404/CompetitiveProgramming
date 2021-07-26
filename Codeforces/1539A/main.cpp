#include <iostream>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long n, x, t;
        scanf("%lld%lld%lld",&n,&x,&t);
        if(x > t){
            printf("0\n");
        } else {
            long long c = min(n, (t/x));
            printf("%lld\n",  c * (n - c) + (c) * (c - 1) / 2);
        }
    }
    return 0;
}
