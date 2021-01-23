#include <iostream>

using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
int n;
ll ans;
ll fact[1000000+3];
int main(){
    scanf("%d",&n);
    ans=0;

    fact[0]=fact[1]=1;
    for(int i=2;i<=n;i++){
        fact[i-1] %= MOD;
        fact[i]=(fact[i-1]%MOD)*(i%MOD);
        fact[i]%=MOD;
    }

    for(int i=1;i<n-1;i++){
        ans += ((fact[i]%MOD)*(fact[n-i]%MOD))%MOD;
        ans %= MOD;
    }

    printf("%lld\n", ans);

    return 0;
}
