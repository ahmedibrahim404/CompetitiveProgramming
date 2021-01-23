#include<bits/stdc++.h>

using namespace std;

int t, n;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        pair<int, int> ns[n];
        int st[n], en[n];
        for(int i=0;i<n;i++){
            scanf("%d%d",&st[i], &en[i]);
            ns[i].first=st[i], ns[i].second=en[i];
        }
        sort(st, st+n);
        sort(en ,en+n);
        int ans=n;
        for(int i=0;i<n;i++){
            int l=ns[i].first, r=ns[i].second;
            int idx=upper_bound(st, st+n, r)-st;
            // n-idx;


            int idx2=lower_bound(en,en+n, l)-en;
            // idx2


            ans=min(ans, n-idx+idx2);

        }
        printf("%d\n", ans);
    }
    return 0;
}
