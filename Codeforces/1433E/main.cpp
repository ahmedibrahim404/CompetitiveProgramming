#include <iostream>

using namespace std;
typedef long long ll;
ll fact[21], n;
int main(){
    fact[0]=1;
    for(int i=1;i<=20;i++) fact[i] = fact[i-1] * i;
    cin >> n;
    ll ans=fact[n]/fact[n/2]/fact[n/2];
    ans /= 2;
    ans *= fact[(n/2-1)];
    ans *= fact[(n/2-1)];
    cout << ans << "\n";
    return 0;
}
