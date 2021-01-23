#include <iostream>

using namespace std;
typedef long long ll;
int T, n;
ll c,d,ma=1e10,mb=1e10, as[51],bs[51];
int main(){
    scanf("%d",&T);
    while(T--){
        c=d=0;
        ma=1e10,mb=1e10;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lld",&as[i]);
            ma=min(ma, as[i]);
            c+=as[i];
        }
        for(int i=0;i<n;i++){
            scanf("%lld",&bs[i]);
            mb=min(mb, bs[i]);
            d+=bs[i];
        }
        ll rem=0;
        for(int i=0;i<n;i++){
            rem+=min(as[i]-ma, bs[i]-mb);
        }
        printf("%lld\n", (c-ma*n)+(d-mb*n)-rem);
    }
    return 0;
}
