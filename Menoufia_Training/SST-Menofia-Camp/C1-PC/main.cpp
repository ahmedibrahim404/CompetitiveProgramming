#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MAX=1e5+3;
int n, rr, avg;
pi ns[MAX];
long double tot=0, mx=0;
int main(){
    scanf("%d %d %d",&n,&rr,&avg);
    for(int i=0;i<n;i++){
        scanf("%d%d",&ns[i].second,&ns[i].first);
        tot += 1.0*ns[i].second;
        mx += (rr-ns[i].second);
    }

    ll l=0, r=mx, ans=0;
    while(r >= l){
        ll mid=(l+r)>>1;
        if((tot + mid)*1.0/n >= avg) r=mid-1, ans=mid;
        else l=mid+1;
    }

    sort(ns, ns+n);
    ll total=0;
    for(int i=0;i<n;i++){
        ll take=min(ans, 1LL*rr-ns[i].second);
        total += ns[i].first*take;
        ans -= take;
    }

    printf("%lld",total);



    return 0;
}
