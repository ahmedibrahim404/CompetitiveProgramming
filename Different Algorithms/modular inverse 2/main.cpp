#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/**

    (1/(a^m))%MOD ???? HOW TO GET IT ?? WHERE MOD IS PRIME
    let a^m=x
    (1/x)%MOD=pow(x, phi(MOD)-1)=pow(x, MOD-2)
    so (1/(a^m))%MOD = (a^m)^(MOD-2) = ( a^ (m (MOD-2) ) )
    it can be simplified if and only if MOD is prime!
    how ??

    by taking modulus of PHI(MOD)=MOD-1 to the exponent

     a^ ((m(MOD-2))%(MOD-1))

**/


//ll modinverse(ll a, ll m, ll MOD){
//    return pow(a, ( (m%(MOD-1)*(MOD-2)%(MOD-1))%(MOD-1) ), MOD);
//}


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

    // power(p,x)%n where gcd(p, n)==1 and p is prime is pow(p, x%phi(n))=pow(p, x%(n-1))
    ll p=pow(19, 8), p2=(pow(19, 8%6));
    // sure p%7==p2%7 if and only if gcd(p, n)==1
    /**
    cout << (p%7) << endl;
    cout << (p2%7) << endl;
    **/

    return 0;
}
