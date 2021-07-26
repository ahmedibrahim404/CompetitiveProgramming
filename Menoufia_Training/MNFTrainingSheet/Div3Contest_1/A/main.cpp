#include<bits/stdc++.h>
using namespace std;
int T, n, ns[51];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&ns[i]);
        sort(ns, ns+n);
        bool can=1;
        for(int i=0;i<n-1;i++){
            if(ns[i+1]-ns[i]>1){
                can=0;
                break;
            }
        }
        if(can)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
