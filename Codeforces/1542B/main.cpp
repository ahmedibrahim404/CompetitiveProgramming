#include <iostream>

using namespace std;
typedef long long ll;

int main(){
    int t;ll n;
    scanf("%d",&t);
    while(t--){
        ll a, b;
        scanf("%lld%lld%lld",&n,&a,&b);
        ll cur=1LL;bool can=0;

        if(a == 1){
            if((n-1)%b == 0) printf("Yes\n");
            else printf("No\n");
            continue;
        }

        while(cur < n){
            if((n-cur)%b==0){
                can=1;
                break;
            }
            cur *= a;
        }
        if(can || cur == n) printf("Yes\n"); else printf("No\n");
    }
    return 0;
}
