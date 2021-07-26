#include<bits/stdc++.h>
using namespace std;
const int MAX=300000+1;
int n;
pair<int, int> ns[MAX];
int main(){
    freopen("oddeven.in","r",stdin);
    freopen("oddeven.out","w",stdout);

    scanf("%d",&n);
    map<int, int> xs, ys;
    for(int i=0;i<n;i++){
        scanf("%d%d",&ns[i].first,&ns[i].second);
        xs[ ns[i].first ]++, ys[ ns[i].second ]++;
    }

    long long ans=0;
    for(int i=0;i<n;i++){
        int x=ns[i].first, y=ns[i].second;
        ans+=max(0LL,1LL*(xs[x]-1)*(ys[y]-1));
    }

    printf("%lld\n", ans);


    return 0;
}
