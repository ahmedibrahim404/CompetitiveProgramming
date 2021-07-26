#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int deg[n];
        for(int i=0;i<n;i++) deg[i]=0;

        pair<ll, int> ns[n];
        ll tot=0;
        for(int i=0;i<n;i++){
            scanf("%lld",&ns[i].first);
            ns[i].second=i;
            tot += ns[i].first;
        }
        sort(ns, ns+n, greater<pair<ll, int>>());
        int idx=0;

        for(int i=0;i<n-1;i++){
            int a, b;
            scanf("%d%d",&a,&b);
            a--, b--;
            deg[a]++;deg[b]++;
        }

        for(int i=0;i<n;i++){
            deg[ ns[i].second ]--;
        }

        printf("%lld ", tot);
        for(int i=0;i<n-2;i++){
            while(!deg[ ns[idx].second ]){
                idx++;
            }
            tot += ns[idx].first;
            if(--deg[ ns[idx].second ]==0) idx++;
            printf("%lld ", tot);
        }
        printf("\n");


    }
    return 0;
}
