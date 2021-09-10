#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int ns[5];
        for(int i=0;i<5;i++) scanf("%d",&ns[i]);
        sort(ns, ns+5);
        int fir=ns[4];int ans=0;
        for(int i=3;~i;i--){
            if(ns[i] != fir){
                ans = fir*ns[i];
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
