#include <iostream>

using namespace std;
typedef long long ll;
const ll MOD=1000000007;

ll pow(ll a, ll b){
    if(!b) return 1;
    ll res;
    res = pow(a, b/2)%MOD;
    res = (res%MOD) * (res%MOD);
    res %= MOD;
    if(b&1) res *= a;
    return res%MOD;
}


string str;
ll k;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> str >> k;
    int n=str.length();
    ll ans=0;
            ll p1=k*n;
            p1 %= MOD-1;

                ll pt2=1-pow(2, p1);
            ll pt3=pow( (1-pow(2, n)), MOD-2 );

    for(int i=0;i<n;i++){
        if(str[i]=='0' || str[i]=='5'){
            ll pt1=pow(2, i)%MOD;
            ans += ((pt1%MOD)*(pt2%MOD))%MOD*(pt3%MOD);
            ans %= MOD;
        }
    }

    cout << ans;

    return 0;
}
