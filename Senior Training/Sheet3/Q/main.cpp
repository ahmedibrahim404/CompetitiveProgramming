#include <iostream>

using namespace std;
typedef long long ll;
int T;ll a, b;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&a,&b);
        if(b%a) printf("-1\n");
        else printf("%lld %lld\n", a, b);
    }
    return 0;
}
