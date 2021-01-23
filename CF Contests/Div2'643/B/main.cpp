#include<bits/stdc++.h>

using namespace std;
int T, n;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int ns[n];
        for(int i=0;i<n;i++) scanf("%d",&ns[i]);
        sort(ns, ns+n);
        int cur=0, ans=0;
        for(int i=0;i<n;i++){
            if(++cur >= ns[i]) cur=0, ans++;
        }

        printf("%d\n", ans);
    }
    return 0;
}
