#include <bits/stdc++.h>
#include <ext/numeric>

#define endl '\n'
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
const int MOD = 98765431;
typedef vector<vector<double>> vvi;


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
        vvi ret(a.size(), vector<double>(b[0].size()));
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b[0].size(); ++j) {
                for (int k = 0; k < a[0].size(); ++k) {
                    ret[i][j] += (1ll*a[i][k] * b[k][j]);
                }

            }
        }
        return ret;
    }
};

vvi identity_element(const matrixMultiply &x) {
    vvi ret(x.n, vector<double>(x.n));
    for (int i = 0; i < x.n; ++i) {
        ret[i][i] = 1;
    }
    return ret;
}

int t;
double p;

int main() {

    cin >> t >> p;
    vvi a = {{1-p, p},{p,1-p}}, b={{1},{0}};
    matrixMultiply m(2);
    a = power(a,t,m); // matrix a power t =>> runs is log(t)
    cout << fixed;
    cout << setprecision(10);
    cout << m(b, a)[0][0] << "\n";
    return 0;
}
