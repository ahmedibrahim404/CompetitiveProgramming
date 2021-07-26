#include <iostream>

using namespace std;
typedef long long ll;
int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ll ns[n];
        for(int i=0;i<n;i++) scanf("%lld",&ns[i]);
        ll ans=0;
        for(int i=n-1;i>=0;i--){
            if(i+ns[i] < n) ns[i] += ns[ i+ns[i] ];
            ans=max(ans, ns[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
