#include<bits/stdc++.h>
using namespace std;

int n, q;
int ns[100000+9], grt[100000+9], add[100000+9];
int main(){
    scanf("%d %d" ,&n, &q);
    int mx=0;
    for(int i=0;i<n;i++) scanf("%d", &ns[i]);
    grt[0]=ns[0];
    int ixx=0;
    for(int i=1;i<n;i++){
        if(ns[i] > grt[i-1]){
            add[ixx++]=grt[i-1];
        } else add[ixx++]=ns[i];
        grt[i]=max(ns[i], grt[i-1]);
    }

    for(int i=0;i<n;i++) if(ns[i]>mx) mx=ns[i];

    long long no;
    for(int i=0;i<q;i++){
        scanf("%lld", &no);
        no--;
        if(no >= n-1){
            printf("%d %d\n", mx, add[no%(n-1)]);
        } else printf("%d %d\n", grt[no], ns[no+1]);
    }
    return 0;
}
