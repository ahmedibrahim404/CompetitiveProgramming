#include <iostream>

using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 3;
int t, n;ll a[N];

int getBit(ll x, int i){
    return x>>i & 1LL;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%lld",&a[i]);
        printf("0 ");
        for(int i=0;i<n-1;i++){

            ll need=0;
            for(int j=0;j<31;j++){
                int b1=getBit(a[i], j), b2=getBit(a[i+1], j);

                if(b1==b2) continue;
                else if(b1==1){
                    need += (1LL<<j);
                }

            }

            a[i+1] ^= need;
            printf("%lld ", need);

        }
        printf("\n");

    }
    return 0;
}
