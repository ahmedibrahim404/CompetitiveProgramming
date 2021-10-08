#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n, H;
        scanf("%d%d",&n,&H);
        vector<ll> v;for(int i=0;i<n;i++){
            ll no;scanf("%lld",&no);
            v.push_back(no);
        }
        sort(v.begin(), v.end());
        ll x=v[n-1], y=v[n-2];
        ll tim = (H+x+y-1)/(x+y);
        ll had = x*(tim) + y*(tim);
        ll ans = 2*tim;
        if(had - y >= H) ans--;
        printf("%lld\n", ans);
    }
    return 0;
}
