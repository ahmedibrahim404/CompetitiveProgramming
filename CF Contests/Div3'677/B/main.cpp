#include<bits/stdc++.h>

using namespace std;
int n;
pair<int, int> ns[1000+3];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ns[i].first);
        ns[i].second=i;
    }
    sort(ns, ns+n, greater<pair<int, int>>());
    int pre=0, ans=0;
    for(int i=0;i<n;i++){
        ans += ns[i].first*pre+1;
        pre++;
    }

    printf("%d\n", ans);
    for(int i=0;i<n;i++ ) printf("%d ", ns[i].second+1);

    return 0;
}
