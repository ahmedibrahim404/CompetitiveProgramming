#include <bits/stdc++.h>
#include <ext/numeric>

#define endl '\n'
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
const int MOD = 1000000009 ;
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
    while(true){
    cin >> t;
    if(!t) break;
    if(t<=3){
        cout << t-1 << "\n";
        continue;
    }
    vvi a = {{0, 0, 1},{1, 0, 1}, {0, 1, 1}}, b={{0, 1, 2}};
    matrixMultiply m(2);
    a = power(a,t-3,m);
    cout << m(b, a)[0][2]%MOD << "\n";

    }
    return 0;
}
