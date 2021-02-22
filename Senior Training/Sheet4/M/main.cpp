#include <iostream>

using namespace std;
typedef long long ll;
ll n, m;int is;
int main(){
    while(scanf("%lld%lld%d",&n,&m,&is)==3 && (n | m | is)){
        ll cnt=0;
        if(n < 8 || m < 8){
            printf("%lld\n", cnt);
            continue;
        }

        ll ns=(n-7), ms=(m-7);
        cnt = (ms/2) * ((ns+1)/2 + ns/2) + (ms%2 ? (ns+1)/2 : 0);
        if(!is) cnt = ns*ms - cnt;
        printf("%lld\n", cnt);
    }
    return 0;
}
