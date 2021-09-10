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
long long binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

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

    int t;
    scanf("%d",&t);
    matrixMultiply ma(2);
    while(t--){
        int n, m;
        scanf("%d%d",&n,&m);
        int nm = m;
        int len=0;
        while(nm){
            nm/=10;
            len++;
        }
        vvi a = {{0, m}};
        vvi b=  {{binpow(10, len)%MOD, 0}, {1, 1}};

        b = power(b, n, ma);
        vvi ret(a.size(), vector<int>(b[0].size()));
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b[0].size(); ++j) {
                for (int k = 0; k < a[0].size(); ++k) {
                    ret[i][j] += (1ll*a[i][k]%MOD * b[k][j]%MOD)%MOD;
                    ret[i][j] %= MOD;
                }

            }
        }
        printf("%d\n", ret[0][0]%MOD);
    }


    return 0;
}
