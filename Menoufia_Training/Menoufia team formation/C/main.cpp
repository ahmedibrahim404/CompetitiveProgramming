#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    double ans=1e9;
    int a, b, c;
    while(n--){
        scanf("%d%d%d",&a,&b,&c);
        ans=min(ans, (double) sqrt( a*a+b*b+c*c ));
    }
    printf("%.3lf\n", ans);
    return 0;
}
