#include <iostream>

using namespace std;
typedef long long ll;

int q;
ll l, r, d, ans;

int main(){

    scanf("%d", &q);

    while(q--){

        scanf("%d %d %d", &l, &r, &d);
        ans=d;

        if( ans >= l && ans <= r ){
            ll mod=r%d;
            ans=r+(d-mod);
        }

        printf("%lld\n", ans);

    }

    return 0;
}
