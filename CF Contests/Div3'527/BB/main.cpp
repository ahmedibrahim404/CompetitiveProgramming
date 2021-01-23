#include <iostream>

using namespace std;
typedef long long ll;
const int MAX=500000+3;

int n;int q;

int main(){
    scanf("%d",&n);
    ll ans;
    ll no;
    for(int i=0;i<n;i++){
        scanf("%lld",&no);
        if(i) ans=no-ans;
        else ans=no;
    }


    int l, r;
    ll v;
    scanf("%d",&q);
    while(q--){
        scanf("%d%d%lld",&l,&r,&v);
        int odd=((r-l+1)+(l%2?1:0))/2;
        int even=(r-l+1)-odd;
        if(n%2==1){
            ans += odd*v;
            ans -= even*v;
        } else {
            ans += even*v;
            ans -= odd*v;
        }

        printf("%lld\n", ans);


    }
    return 0;
}
