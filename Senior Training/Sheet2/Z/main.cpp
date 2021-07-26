#include<bits/stdc++.h>

using namespace std;

int t, n;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ns[3*n + 5];
        for(int i=0;i<3*n;i++){
            scanf("%d",&ns[i]);
        }
        sort(ns, ns+3*n);int ans=0;
        for(int i=n;i<3*n-1;i+=2){
            ans += ns[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
