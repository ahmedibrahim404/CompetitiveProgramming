#include <iostream>
#include<algorithm>
using namespace std;

int n, t;
typedef long long ll;
int main(){
    scanf("%d",&t);
    int cs=1;
    while(t--){
        scanf("%d",&n);
        ll as[n], bs[n];
        for(int i=0;i<n;i++) scanf("%lld",&as[i]);
        for(int i=0;i<n;i++) scanf("%lld",&bs[i]);
        sort(as, as+n);
        sort(bs, bs+n, greater<ll>());
        ll ans=0;
        for(int i=0;i<n;i++){
            ans += (long long) as[i] * bs[i];
        }
        printf("Case #%d: %lld\n", cs++, ans);
    }
    return 0;
}
