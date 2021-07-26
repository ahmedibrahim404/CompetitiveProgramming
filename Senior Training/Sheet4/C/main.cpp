#include <bits/stdc++.h>
#include <ext/numeric>

#define endl '\n'
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
const int MOD = 1000000007 ;
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

long long t;

int main() {
    cin >> t;
    if(t==0){
        cout << 0;
        return 0;
    } else if(t == 1){
        cout << 1;
        return 0;
    }
    vvi a = {{0, 1},{1,1}}, b={{0, 1}};
    matrixMultiply m(2);
    a = power(a,t-1,m); // matrix a power t =>> runs is log(t)
    vvi ans=m(b, a);
    cout << ans[0][1]%MOD << "\n";
    return 0;
}
