#include <bits/stdc++.h>
#include <ext/numeric>

#define endl '\n'
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
const int MOD = 1000000007 ;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;


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
        vvi ret(a.size(), vector<int>(b[0].size()));
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b[0].size(); ++j) {
                for (int k = 0; k < a[0].size(); ++k) {
                    ret[i][j] += (1ll*a[i][k]%MOD * b[k][j]%MOD)%MOD;
                    ret[i][j] %= MOD;
                }

            }
        }
        return ret;
    }
};

vvi identity_element(const matrixMultiply &x) {
    vvi ret(x.n, vector<int>(x.n));
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
    ns=vvi(n, vi(n, 0));
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        ns[a-1][b-1]=1;
    }

    int ans=0;
    matrixMultiply m(2);
    vvi a = power(ns,k,m); // matrix a power t =>> runs is log(t)
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans = (1LL * ans + a[i][j])%MOD;
            ans %= MOD;
        }
    }

    printf("%d\n", ans);
    return 0;
}
