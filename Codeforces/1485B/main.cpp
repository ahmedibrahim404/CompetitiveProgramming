#include <iostream>

using namespace std;
typedef long long ll;
int n, q;ll k;
ll ns[100000+3];
int main(){
    scanf("%d%d%lld",&n,&q,&k);
    for(int i=0;i<n;i++){
        scanf("%lld",&ns[i]);
    }

    ll can[n];
    for(int i=0;i<n;i++) can[i]=0;
    for(int i=0;i<n;i++){
        if(i==0) can[i] = ns[i]-1;
        if(i == n-1) can[i] = k - ns[i];
        if(i) can[i] += (ns[i]-ns[i-1]-1);
        if(i+1 != n) can[i] += (ns[i+1]-ns[i]-1);
    }

    for(int i=0;i<n;i++) if(i) can[i] += can[i-1];

    int a, b;
    while(q--){
        scanf("%d%d",&a,&b);
        a--, b--;
        ll ans=0;

        ans += (can[b]-(a ? can[a-1] : 0 ));

        ans += k - (b +1 != n ? ns[b+1]-1 : k);
        ans += (a - 1 != -1 ? ns[a-1]+1 : 1) - 1;


        printf("%lld\n", ans);

    }




    return 0;
}
