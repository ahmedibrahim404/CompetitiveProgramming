#include<bits/stdc++.h>
using namespace std;

int t, n, k;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        int ns[n];
        for(int i=0;i<n;i++) scanf("%d",&ns[i]);
        sort(ns,ns+n);
        long long ans=0;
        for(int i=1;i<n;i++){
            if(ns[i]>=k) break;
            ans += (long long) (-ns[i]+k)/ns[0];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
