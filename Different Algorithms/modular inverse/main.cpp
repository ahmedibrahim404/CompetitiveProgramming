#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX=100000+3;
const ll MOD=1000000007;
int N;
ll ns[MAX];


ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}


/** another way **/


ll pow(ll a, ll b, ll mod){

    if(b==0) return 1;
    ll ans;
    ll r=pow(a, b/2, mod);
    ans = (r*r)%mod;
    if(b&1) ans *= a;
    ans %= mod;
    return ans;

}

ll pow(ll a, ll b){

    if(b==0) return 1;
    ll ans;
    ll r=pow(a, b/2);
    ans = (r*r);
    if(b&1) ans *= a;
    return ans;

}

ll phi(ll x){

    vector<bool> vi(31622+9, 1);
    vi[0]=0, vi[1]=0;
    ll ans=1;
    for(ll i=2;i*i<=x;i++){
        if(!vi[i]) continue;
        for(ll j=i*i;j*j<=x;j+=i){
            vi[j]=0;
        }
        if(x%i) continue;
        int cnt=0;
        while(x/i){
            x/=i;
            cnt++;
        }

        ans *= pow(i, cnt-1)*(i-1);
    }

    if(x){
        ans *= x-1;
    }

    return ans;

}


int main(){

    pow(2, 1e9+7);

    ll ans=0;
    ll mi;

    /**
    ll mi=1;ll y;
    gcd(ns[i-1], MOD, mi, y);
    **/

    /**
    // MOD MUST BE PRIME !!!!!
    mi=pow(ns[i-1], MOD-2, MOD);
    *//

    /**

    // Eulter method
    ll pi=phi(MOD);
    gcd(ns[i-1], MOD)==1
    mi=pow(ns[i-1], pi-1, MOD);
    **/

//    Fourth way=> ranges for prime p
//    suppose we want modular inverse from 1 to p-1 for mod p
    vector<int> inv(p, 1);
    for(int i=2;i<p;i++){
        inv[i]=(p-(p/i)*inv[p%i]%p)%p
    }



    return 0;
}
