#include <iostream>

using namespace std;

int n, h, m, l, r, d;
int talls[51];

int main(){

    scanf("%d %d %d", &n, &h, &m);
    for(int i=0;i<n;i++) talls[i]=h;

    for(int i=0;i<m;i++){
        scanf("%d %d %d", &l, &r, &d);
        l--, r--;
        for(int j=l;j<=r;j++) talls[j]=min(talls[j], d);
    }

    long long ans=0;
    for(int i=0;i<n;i++){
        ans += talls[i]*talls[i];
    }

    printf("%lld", ans);


    return 0;
}
