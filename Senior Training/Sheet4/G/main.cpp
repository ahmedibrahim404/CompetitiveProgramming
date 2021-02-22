#include <bits/stdc++.h>
#include <ext/numeric>

#define endl '\n'
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
const int MOD = 98765431;
typedef vector<vector<ll>> vvi;
ll mod;

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
        vvi ret(a.size(), vector<ll>(b[0].size()));
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b[0].size(); ++j) {
                for (int k = 0; k < a[0].size(); ++k) {
                    ret[i][j] += (a[i][k]%mod * b[k][j]%mod)%mod;
                    ret[i][j] %= mod;
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

ll n, cc;
int main() {

    int d=1;
    while(cin >> n >> cc && (n || cc)){
        if(!n){
            cout << "Case " << d++ << ": " << n << " " << cc << " " << 1 << "\n";
            continue;
        }
        n--;
        vvi a = {{0, 1, 0, 0, 0},{1, 1, 0, 0, 0}, {0, 0, 0, 1, 0}, {0, 0, 1, 1, 0}, {0, 0, 0, 1, 1}}, b={{0, 1, 1, 1, 1}};
        mod=cc;
        matrixMultiply m(5);
        a = power(a,n,m);
        vvi ans=m(b, a);
        cout << "Case " << d++ << ": " <<n+1 << " " << cc << " " << ans[0][3]%mod << "\n";
    }
    return 0;
}
