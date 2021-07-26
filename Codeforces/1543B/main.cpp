#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){

    int t, n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);ll ns[n];
        for(int i=0;i<n;i++) scanf("%lld",&ns[i]);
        sort(ns, ns+n);
        ll need=0;
        for(int i=0;i<n;i++){
            need += ns[i] - ns[n/2];
        }

        need = abs(need);
        need -= n*(need/n);

        printf("%lld\n", need*(n-need));



    }

    return 0;
}
