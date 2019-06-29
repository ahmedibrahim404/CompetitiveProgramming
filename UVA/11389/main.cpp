#include<bits/stdc++.h>
using namespace std;

int n, d, r;
int ns[100+9], ms[100+9];
int main(){

    while(scanf("%d %d %d", &n, &d, &r)){
        if(!n && !d && !r) break;
        for(int i=0;i<n;i++) scanf("%d", &ns[i]);
        for(int i=0;i<n;i++) scanf("%d", &ms[i]);

        sort(ns, ns+n);
        sort(ms, ms+n);

        long long sum=0;
        for(int i=0;i<n;i++){
            int total = ns[i] + ms[n-i-1];
            if(total > d) sum += (total-d)*r;
        }

        printf("%lld\n", sum);
    }

    return 0;
}
