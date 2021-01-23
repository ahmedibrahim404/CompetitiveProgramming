#include <iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
ll n;
pi ns[300000+9];

int main(){

    scanf("%lld", &n);
    for(ll i=0;i<n;i++){
        scanf("%lld", &ns[i].first);
        ns[i].second=i;
    }

    ll fir=ns[0].first, las=ns[n-1].first;
    sort(ns, ns+n);

    ll st=0, en=1e9, ans=0;
    for(int i=0;i<61;i++){
        ll mid = (st+en) /2 ;
        if(mid*(n-1) <= min(fir, las) && mid * abs(ns[0].second-ns[1].second) <= min(ns[0].first, ns[1].first) ){
            st=mid+1;
            ans=max(ans, mid);
        } else en=mid-1;
    }

    printf("%lld", ans);

    return 0;
}
