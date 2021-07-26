#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t, n, m;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        ll as[n], bs[m];
        for(int i=0;i<n;i++) scanf("%lld",&as[i]);
        for(int i=0;i<m;i++) scanf("%lld",&bs[i]);
        sort(as, as+n, greater<ll>());
        int cur=0;
        ll ans=0;
        for(int i=0;i<n;i++){
                if(bs[ as[i]-1 ] > bs[cur]){
                ans += bs[ cur ];
                cur++;
            }
            else {
                ans += bs[ as[i]-1 ];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
