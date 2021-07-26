#include<bits/stdc++.h>
#define int long long int
using namespace std;
main(){
    int x[7],y[7],i,area,x1,x2,y1,y2;
    for(i=1;i<7;i++)scanf("%lld%lld",&x[i],&y[i]);
    area=(x[2]-x[1])*(y[2]-y[1]);
    for(i=3;i<7;i++){
        x[i]=max(x[i],x[1]);
        y[i]=max(y[i],y[1]);
        x[i]=min(x[i],x[2]);
        y[i]=min(y[i],y[2]);
    }
    area-=(x[4]-x[3])*(y[4]-y[3]);
    area-=(x[6]-x[5])*(y[6]-y[5]);
    x1=max(x[3],x[5]);
    y1=max(y[3],y[5]);
    x2=min(x[4],x[6]);
    y2=min(y[4],y[6]);
    area+=abs((x2-x1)*(y2-y1));
    if(area>0)puts("YES");
    else puts("NO");
}
