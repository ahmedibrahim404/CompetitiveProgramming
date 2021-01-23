#include <iostream>

using namespace std;
typedef long long ll;
int n, l, r;
ll s1=0, s2=0;
int main(){
    scanf("%d%d%d",&n,&l,&r);
    ll cur=1, cur2=1;
    for(int i=0;i<l;i++){
        s1 += cur;
        cur *= 2;
    }
    for(int i=0;i<r;i++){
        s2 += cur2;
        cur2 *= 2;
    }
    s1 += (n-l);
    s2 += (n-r)*(cur2/2);
    printf("%lld %lld", s1, s2);
    return 0;
}
