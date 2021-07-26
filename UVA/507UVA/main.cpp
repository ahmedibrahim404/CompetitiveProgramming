#include <iostream>

using namespace std;

int n, t, ns[20000+3];

int main(){
    scanf("%d",&t);
    for(int ts=1;ts<=t;ts++){
          scanf("%d",&n);
        for(int i=0;i<n-1;i++){
            scanf("%d",&ns[i]);
            if(i) ns[i] += ns[i-1];
        }

        int mi=0, midx=-1;
        int mx=0, len=0, st=-1;
        for(int i=0;i<n-1;i++){
            if(ns[i]-mi>mx)mx=ns[i]-mi,len=i-midx,st=i;
            if(ns[i]-mi==mx){
                if(i-midx>len)len=i-midx,st=i;
            }
            if(ns[i]<mi) mi=ns[i], midx=i;
        }

        if(mx==0) printf("Route %d has no nice parts\n", ts);
        else printf("The nicest part of route %d is between stops %d and %d\n", ts, st-len+2, st+2);
    }




    return 0;
}
