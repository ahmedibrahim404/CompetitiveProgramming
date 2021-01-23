#include <iostream>

using namespace std;
typedef long long ll;
int n;
ll t;

int main(){
    scanf("%d",&n);
    ll ans=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&t);
        ans += t*3;
    }
    printf("%lld\n", ans);
    return 0;
}
