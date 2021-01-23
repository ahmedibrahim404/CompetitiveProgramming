#include<bits/stdc++.h>
using namespace std;
int t, ns[51], n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&ns[i]);
        sort(ns, ns+n);
        int mi=1e9;
        for(int i=0;i<n-1;i++) mi=min(mi, ns[i+1]-ns[i]);
        printf("%d\n", mi);
    }
    return 0;
}
