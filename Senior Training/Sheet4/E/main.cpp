#include <bits/stdc++.h>
#include <ext/numeric>

#define endl '\n'
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
const long long MOD = 4294967296;
typedef vector<unsigned int> vi;
typedef vector<vector<unsigned int>> vvi;


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
        vvi ret(a.size(), vector<unsigned int>(b[0].size()));
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b[0].size(); ++j) {
                for (int k = 0; k < a[0].size(); ++k) {
                    ret[i][j] += (a[i][k] * b[k][j]);
                }

            }
        }
        return ret;
    }
};

vvi identity_element(const matrixMultiply &x) {
    vvi ret(x.n, vector<unsigned int>(x.n));
    for (int i = 0; i < x.n; ++i) {
        ret[i][i] = 1;
    }
    return ret;
}

unsigned int k;
vvi ns;

int convert(int x, int y){
    return x * 8 + y;
}

int xs[] = {2, 2, -2, -2, 1, 1, -1, -1};
int ys[] = {1, -1, 1, -1, 2, -2, 2, -2};

int main() {
    cin >> k;
    k++;
    ns=vvi(65, vi(65, 0));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            for(int k=0;k<8;k++){
                int ni=i+xs[k], nj=j+ys[k];
                if(ni >= 8 || nj >= 8 || ni < 0 || nj < 0) continue;
                ns[ convert(i, j) ][ convert(ni, nj) ] = 1;
            }
        }
    }
    for(int i=0;i<=64;i++){
        ns[i][64]=1;
    }

//    for(int i=0;i<65;i++){
//        for(int j=0;j<65;j++){
//            cout << ns[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";    matrixMultiply m(65);

//    vvi a = power(ns,2,m);
//
//    for(int i=0;i<65;i++){
//        for(int j=0;j<65;j++){
//            cout << a[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";

    matrixMultiply m(65);
    vvi a = power(ns,k,m);
    cout << a[0][64] << "\n";
    return 0;
}
