#include <iostream>

using namespace std;
typedef long long ll;


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll a, b;
        scanf("%lld%lld",&a,&b);

        if(a==b){
            printf("0 0\n");
            continue;
        }

        if(a > b) swap(a, b);
        printf("%lld %lld\n", b-a, min(b%(b-a), (b-a) - b%(b-a)));

    }

    return 0;
}
