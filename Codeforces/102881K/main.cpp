#include <iostream>

using namespace std;
typedef long long ll;
const ll OO = 2e18;

int main(){
    freopen("plants.in", "r", stdin);
    int n;
    scanf("%d",&n);ll a[n], b[n];
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    for(int i=0;i<n;i++) scanf("%lld",&b[i]);

    ll st=0, en=OO;

    for(int i=1;i<n;i++){
        // a[i] + t * b[i] >= a[i-1] + t * b[i-1]
        // t*(b[i] - b[i-1]) >= a[i-1]-a[i]

        ll fir = abs(a[i-1] - a[i]);
        ll sec = abs(b[i] - b[i-1]);

        ll till = (fir + sec - 1) / sec;

        if((b[i] - b[i-1] < 0) ^ (a[i-1] - a[i] < 0)){
            if(a[i-1]-a[i] < 0) continue;
             else en=-1;
        }
        else if(b[i] - b[i-1] > 0) st=max(st, till);
        else en = min(en, till);
    }

    if(st > en) printf("-1\n");
    else printf("%lld\n", st);



    return 0;
}
