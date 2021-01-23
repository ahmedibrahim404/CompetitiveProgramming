#include<bits/stdc++.h>

using namespace std;

int t, n;

int main(){
    scanf("%d",&t);
    while(t--){
            int d;
        scanf("%d%d",&n,&d);
        int ns[n];
        for(int i=0;i<n;i++) scanf("%d",&ns[i]);
        sort(ns, ns+n);

        bool can=1;
        for(int i=0;i<n;i++){
            if(ns[i] > d) can=0;
        }

        if(can){
            printf("YES\n");
            continue;
        }

        if(ns[0] + ns[1] <= d){
            printf("YES\n");
        } else printf("NO\n");
    }
    return 0;
}
