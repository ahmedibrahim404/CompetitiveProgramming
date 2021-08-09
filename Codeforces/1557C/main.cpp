#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200000 + 3;const int M = 1e9+7;

ll t, n, k, cm;
ll nCr[N];
ll mem[N][2];

ll power(ll a, ll b, ll m){
    if(!b)  return 1;
    ll t = power(a, b>>1, m)%m;
    return ((t*t)%m * (b&1 ? a : 1)%m)%m;
}

ll modinv(ll x){
    return power(x, M-2, M);
}


void calc()
{
    nCr[0] = 1;
    nCr[1] = n;
    nCr[2] = (n * (n-1))/2;

    for(int i=3; i<=n; ++i)
    {
        nCr[i] = (((n-i+1) * nCr[i-1])%M * modinv(i))%M;
    }
}

ll solve(ll idx, bool gr){
    if(idx == k) return 1;
    if(mem[idx][gr] != -1) return mem[idx][gr];

    ll ret = 0;

    if(gr == 1){
        ret = (solve(idx+1, 1) * power(2, n, M))%M;
    }
    else {
        if(n%2 == 0){
            ret = (solve(idx+1, 0) * (cm))%M;
            ret = (ret + solve(idx+1, 1))%M;
        } else {
            ret = (solve(idx+1, 0) * cm)%M;
            ret += solve(idx+1, 0) %M;
            ret %= M;
        }
    }

    //cout << idx << " && " << gr << " : " << op1+op2 << endl;
    return mem[idx][gr] = ret;

}


int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(k == 0){
            cout << 1 << endl;
            continue;
        }

        calc();
        cm = 0;
        if(n%2 == 0){
            for(int i=0; i<=n-2; i+=2){
                cm = (cm + nCr[i])%M;
            }
        }
        else {
            for(int i=0; i<=n-1; i+=2){
                cm = (cm + nCr[i])%M;
            }
        }

        for(int i=0; i<k; ++i) mem[i][0] = mem[i][1] = -1;
        ll ans = solve(0, 0);
        cout << ans << endl;
    }




}
