#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

ll C[200000+5][100+5];

int t, n, m, k;

int main(){
    scanf("%d",&t);

    for(int i=0;i<200000+1;i++) C[i][0]=1;
    for(int i=1;i<200000+1;i++){
        for(int j=1;j<100+1;j++){
            C[i][j]=C[i-1][j]%MOD+C[i-1][j-1]%MOD;
            C[i][j]%=MOD;
        }
    }

    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        int ns[n];
        for(int i=0;i<n;i++){
            scanf("%d",&ns[i]);
        }

        sort(ns, ns+n);

        ll ans=0;
        for(int i=0;i<n;i++){
            int cur=ns[i];
            int idx=lower_bound(ns, ns+n, cur-k)-ns;
            int items=i-idx;
            if(items >= m-1) ans += C[items][m-1]%MOD;
            ans %= MOD;
        }

        printf("%lld\n", ans);

    }
    return 0;
}
