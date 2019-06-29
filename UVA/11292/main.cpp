#include<bits/stdc++.h>
using namespace std;

int n, m;
int ns[20000], ms[20000];
int main(){
    while( scanf("%d %d", &n, &m) ){

        if(!n && !m) break;

        for(int i=0;i<n;i++) scanf("%d", &ns[i]);
        for(int i=0;i<m;i++) scanf("%d", &ms[i]);
        if(n > m){
            printf("Loowater is doomed!\n");
            continue;
        }

        sort(ns, ns+n);
        sort(ms, ms+m);


        int idx=0, taken=0;
        long long total=0;
        for(int i=0;i<n && idx < m;i++){

            if( ms[idx] >= ns[i] ) {
                taken++;
                total += ms[idx];
                idx++;
                continue;
            } else idx++, i--;

        }

        if(taken == n) printf("%lld\n", total);
        else printf("Loowater is doomed!\n");

    }





    return 0;
}
