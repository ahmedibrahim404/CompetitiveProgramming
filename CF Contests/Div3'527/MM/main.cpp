#include <iostream>

using namespace std;
typedef long long ll;
const int MAX=200000+3;
int n;
ll t, d;
int main(){
    scanf("%d",&n);
    ll ans=0;
    for(int i=0;i<n;i++){
        cin >> t >> d;
        if(t>ans) ans=t;
        ans += d;
    }
    printf("%lld\n", ans);
    return 0;
}
