#include<bits/stdc++.h>

using namespace std;
int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ns[n];
        int sum=0;
        for(int i=0;i<n;i++){
            scanf("%d",&ns[i]);
            sum += ns[i];
        }
        sort(ns, ns+n);
        int st=0, en=ns[n-1], ans=ns[n-1];
        while(en >= st){
            int mid=(st+en)/2;
            if(mid*n >= sum) ans=mid, en=mid-1;
            else st=mid+1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
