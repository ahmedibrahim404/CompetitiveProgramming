#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll s, mi=1e12, tot=0;
ll ns[1000+9];

int main(){

    scanf("%d %lld", &n, &s);
    for(int i=0;i<n;i++){
        scanf("%lld", &ns[i]);
        tot += ns[i];
        mi=min(ns[i], mi);
    }

    if(tot < s) return printf("-1\n"), 0;

    sort(ns, ns+n);

    for(int i=0;i<n;i++){
        ll re=(ns[i] - mi);;
        s -= re;
        ns[i] -= re;
        tot -= re;
        if(s <= 0) break;
    }

    if(s > 0){
        mi -= ceil((double)s/n);
    }

    printf("%lld\n", mi);

    return 0;
}
