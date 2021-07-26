#include <iostream>

using namespace std;
typedef long long ll;
int t, n;ll x;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%lld",&n,&x);
        ll no;
        ll mx=0, mi=0;
        for(int i=0;i<n;i++){
            scanf("%lld",&no);
            mx += (no+x-1)/x;
            mi += no;
        }
        mi = (mi+x-1)/x;
        printf("%lld %lld\n", mi, mx);
    }
    return 0;
}
