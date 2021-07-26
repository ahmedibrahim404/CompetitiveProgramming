#include <iostream>
#include<algorithm>
using namespace std;

int q,n, k, ns[100+9];
int main(){
    scanf("%d", &q);
    while(q--){
        scanf("%d %d",&n, &k);
        for(int i=0;i<n;i++) scanf("%d", &ns[i]);
        sort(ns, ns+n);
        int ans=ns[0]+k;
        if(ns[n-1]-k > ans) ans=-1;
        printf("%d\n", ans);
    }
    return 0;
}
