#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q, a, b, ones[100000+9];
char s[100000+9], sr[100000+9];
const ll MOD = 1e9 + 7;

inline ll power(ll x, ll p, ll m){
    ll res = 1;
    while(p){
        if(p & 1)
            res = ((res % m) * (x % m)) % m;
        x = ((x % m) * (x % m)) % m;
        p >>= 1;
    }
    return res % m;
}

int main(){

    scanf("%d %d", &n, &q);
    scanf("%s", s);

    for(int i=0;i<n;i++){
        if(i) ones[i] = ones[i-1];
        if(s[i] == '1') ones[i]++;
    }

    while(q--){

        scanf("%d %d", &a, &b);
        a--, b--;
        int os=ones[b] - ones[a-1];
        int zs=b-a+1-os;

        ll res=power(2, os, MOD)-1;
        res += ( res * ( power(2, zs, MOD) - 1 ) );
        res %= MOD;

        printf("%lld \n", res);

    }

    return 0;
}
