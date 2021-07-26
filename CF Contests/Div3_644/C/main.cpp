#include<bits/stdc++.h>
using namespace std;

int t, n, ns[51];
int pr=0, odds=0, evens=0;
int main(){
    scanf("%d",&t);
    while(t--){
        pr=0, odds=0, evens=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
             scanf("%d",&ns[i]);
             if(ns[i]%2) odds++;
             else evens++;
        }
        sort(ns, ns+n);
        for(int i=0;i<n-1;i++) if(ns[i+1]-ns[i]==1) pr++;
        odds %= 2;
        evens %= 2;
        if((odds+evens == 2&&pr) || (!odds && !evens)) printf("YES\n");
        else printf("NO\n");

    }
    return 0;
}
