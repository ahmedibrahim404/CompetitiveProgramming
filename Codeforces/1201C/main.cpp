#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll k,ns[200000+3], diff=0;

int main(){

    scanf("%d%lld",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%lld",&ns[i]);
    }
    sort(ns, ns+n);


    ll mid=ns[ n/2 ];
    for(int i=(n/2)+1;i<n;i++){
        diff += ns[i]-ns[n/2];
    }

    ll st=0, en=2e9;
    ll ans=0;
    while(en>=st){
        ll mid=(st+en)>>1;
        if( 1LL*mid+1LL*(n/2)*mid <= 1LL*k+1LL*diff ){
            ans=max(ans, 1LL*mid);
            st=mid+1;
        } else en=mid-1;
    }

    printf("%lld\n", 1LL*ns[n/2]+ans);

    return 0;
}
