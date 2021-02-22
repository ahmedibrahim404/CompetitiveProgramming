#include <bits/stdc++.h>
#include <ext/numeric>

#define endl '\n'
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
const int MOD = 98765431;
typedef vector<vector<ll>> vvi;


/**
    You should consider it in problems at which you are performing process
    and you need the result after ((k)) processes
**/
ll mod;
struct matrixMultiply {
    int n;

    matrixMultiply(int x) {
        n = x;
    }

    vvi operator()(const vvi &a, const vvi &b) {
        vvi ret(a.size(), vector<ll>(b[0].size()));
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b[0].size(); ++j) {
                for (int k = 0; k < a[0].size(); ++k) {
                    (ret[i][j] += (a[i][k] * b[k][j]) % mod) %= mod;
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

ll d, n;
int main() {

    while(scanf("%lld%lld%lld",&d,&n,&mod) == 3 && (d || n || mod)){
        vvi b=vvi(1, vector<ll>(d, 0));
        vvi a=vvi(d, vector<ll>(d, 0));

        for(int i=d-1;i>=0;i--){
            scanf("%lld",&a[i][d-1]);
            a[i][d-1] %= mod;
        }
        for(int i=0;i<d;i++){
            scanf("%lld",&b[0][i]);
            b[0][i]%=mod;
        }

        for(int i=1;i<d;i++){
            a[i][i-1]=1;
        }

        if(n <= d){
            printf("%lld\n", b[0][n-1]);
            continue;
        }

        matrixMultiply m(d);
        a = power(a,n-d,m);
        vvi res=m(b, a);
        printf("%lld\n", res[0][d-1]);

    }

    return 0;
}
