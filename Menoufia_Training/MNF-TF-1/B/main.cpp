#include<bits/stdc++.h>
using namespace std;
int T, R, L, cs=1;
int main(){
    freopen("dalia.in","r", stdin);

    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&R,&L);
        double a=2*(22.0/7)*R;
        double b=1.0*L/a;
        printf("Case %d: %d\n", cs++, (int) b);
    }

    return 0;
}
