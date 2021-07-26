#include<bits/stdc++.h>
using namespace std;

int n;
typedef pair<int, int> pi;
pi ns[200000+9];
int ans[200000+9];
typedef long long ll;
ll big, total=0;;
int main(){
    int idx=0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &ns[i].first);
        ns[i].second=i+1;
        total += ns[i].first;
    }
    sort(ns, ns+n, greater< pair<int, int> >());


    for(int i=0;i<n;i++){
        ll t=total;

        big=1LL*ns[0].first;
        if(i == 0)
            big=ns[i+1].first;

        t-= big;
        t-=ns[i].first;

        if(big == t) ans[idx++]=ns[i].second;

    }

    printf("%d\n", idx);
    for(int i=0;i<idx;i++) printf("%d ", ans[i]);
    return 0;
}
