#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=100000+3;
int n, ns[MAX];

int main(){
    scanf("%d",&n);
    map<ll, int> mp;
    for(int i=0;i<n;i++){
        ll no;
        scanf("%lld",&no);
        if(mp.find(no)==mp.end()) mp[no]=1;
        else mp[no]++;
    }


    auto it=mp.begin();
    ll ans=0, preans=0;
    for(;it!=mp.end();it++){

        ll cur=it->first;

        ll pre=1;
        while(pre <= 2e9){
            pre *= 2;
            if(pre <= cur) continue;
            if(mp.find(pre-cur)==mp.end()) continue;
            if(pre-cur==cur) preans += 1LL*(1LL*mp[cur]*(mp[cur]-1))/2;
            else ans += 1LL*mp[pre-cur] * mp[cur];
        }

    }

    printf("%lld\n", ans/2+preans);

    return 0;
}
