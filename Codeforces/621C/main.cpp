#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 * 3;
long long x[maxn];
long long y[maxn];

int main() {
    int n = 0;
    int p = 0;
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        int l, r ;
        cin >> l >> r;
        x[i] = r / p - (l - 1) / p;
        y[i] = (r - l + 1);
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
        int ne = (i + 1) % n;
        double all = y[i] * y[ne];
        double good = x[i] * y[ne] + x[ne] * y[i] - x[ne] * x[i];
        ans += (good*2000) / all;
    }
    cout.precision(1000);
    cout << ans;
}
