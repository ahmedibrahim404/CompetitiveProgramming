#include<bits/stdc++.h>
using namespace std;

int T, n, ns[100000+9];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&ns[i]);
        sort(ns, ns+n, greater<int>());
        printf("%d\n",min(ns[1]-1, n-2));
    }
    return 0;
}
