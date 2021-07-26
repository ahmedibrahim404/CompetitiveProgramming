#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=200000+3;
int n, ns[MAX];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&ns[i]);
    sort(ns, ns+n);
    long long ans=0;
    for(int i=n-3;i>=0;i-=3){
        ans += (long long) ns[i];
    }
    printf("%lld\n", ans);
    return 0;
}
