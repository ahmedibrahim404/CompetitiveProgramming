#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t, n, k;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        ll ns[n];
        for(int i=0;i<n;i++) scanf("%lld",&ns[i]);
        sort(ns, ns+n, greater<int>());
        for(int i=1;i<n, k;i++, k--){
            ns[0] += ns[i];
        }
        printf("%lld\n", ns[0]);
    }
    return 0;
}
