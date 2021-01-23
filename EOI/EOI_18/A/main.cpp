#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
pi ns[100000+9];
int T, n, A, B;

bool cmpr(pi p2, pi p1){
    return (p2.first-p2.second)>( p1.first-p1.second);
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d", &n, &A, &B);
        for(int i=0;i<n;i++) scanf("%d %d", &ns[i].first, &ns[i].second);
        sort(ns, ns+n, cmpr);
//        for(int i=0;i<n;i++) printf("%d %d\n", ns[i].first, ns[i].second);
        int idx=n-1;
        ll sum=0;
        int re=B;
        while(re--){
            sum += ns[idx--].second;
        }

        idx=0;
        while(A--){
            sum += ns[idx++].first;
        }

        for(int i=idx;i<n-B;i++){
            sum += max(ns[i].first, ns[i].second);
        }

        printf("%lld\n", sum);

    }


    return 0;
}
