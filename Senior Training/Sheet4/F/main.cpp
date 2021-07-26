#include <bits/stdc++.h>
#include <ext/numeric>

#define endl '\n'
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;


/**
    You should consider it in problems at which you are performing process
    and you need the result after ((k)) processes
**/

struct matrixMultiply {
    int n;

    matrixMultiply(int x) {
        n = x;
    }

    vvi operator()(const vvi &a, const vvi &b) {
        vvi ret(a.size(), vector<ll>(b[0].size(), 2e18));
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b[0].size(); ++j) {
                for (int k = 0; k < a[0].size(); ++k) {
                    if(a[i][k] != 2e18 && b[k][j] != 2e18)
                    ret[i][j] = min(ret[i][j], a[i][k] + b[k][j]);
                }

            }
        }
        return ret;
    }
};

vvi identity_element(const matrixMultiply &x) {
    vvi ret(x.n, vector<ll>(x.n));
    for (int i = 0; i < x.n; ++i) {
        ret[i][i] = 1;
    }
    return ret;
}

long long k;
int n, m;
vvi ns;
int main() {
    scanf("%d%d%lld",&n,&m,&k);
    ns=vvi(n, vi(n, 2e18));
    for(int i=0;i<m;i++){
        int a, b;ll c;
        scanf("%d%d%lld",&a,&b,&c);
        ns[a-1][b-1]=c;
    }

    matrixMultiply m(n);
    vvi a = power(ns,k,m);
    ll ans=2e18;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] < 2e18) ans=min(ans, a[i][j]);
        }
    }
    if(ans == 2e18) printf("IMPOSSIBLE\n"); else
    printf("%lld\n", ans);
    return 0;
}
