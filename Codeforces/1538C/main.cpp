#include<bits/stdc++.h>
using namespace std;

int t;

int main(){
    scanf("%d",&t);
    while(t--){
        int n, l, r;
        scanf("%d%d%d",&n,&l,&r);
        int ns[n];
        long long ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",&ns[i]);
        }
        sort(ns, ns+n);
        for(int i=0;i<n;i++){

            int cur=ns[i];
            int idx=lower_bound(ns+i+1, ns+n, l-cur)-ns;
            int idx2=upper_bound(ns+i+1, ns+n, r-cur)-ns;

            if(idx > idx2) continue;

            ans += (1LL ) * (idx2-idx);

        }
        printf("%lld\n", ans);
    }
    return 0;
}
