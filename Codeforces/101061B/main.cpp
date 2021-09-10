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

    ns=vvi(3, vi(3, 0));
    ns={{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    int t;
    scanf("%d",&t);    matrixMultiply m(2);

    while(t--){
        int n;
        scanf("%d",&n);
        n--;
        if(!n){
            printf("3\n");
            continue;
        }
        vvi a = power(ns, n, m);
        vvi b = vvi(1, vi(3));
        b = {{1, 1, 1}};
        swap(a, b);
        vvi ret(a.size(), vector<int>(b[0].size()));
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b[0].size(); ++j) {
                for (int k = 0; k < a[0].size(); ++k) {
                    ret[i][j] += (1ll*a[i][k]%MOD * b[k][j]%MOD)%MOD;
                    ret[i][j] %= MOD;
                }

            }
        }
        long long ans=0;
        for(int i=0;i<3;i++) ans += 1LL * ret[0][i]%MOD, ans%=MOD;
        printf("%lld\n", ans%MOD);
    }


    return 0;
}
