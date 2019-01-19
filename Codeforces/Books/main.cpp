#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, t, x, f[100000 + 5];
int ans = 0;

void solve() {
    for(int i=1;i<=n;i++) {
        int lo = i, hi = n, mi, tmp;
        while(lo <= hi) {
            mi = (lo + hi) / 2;
            if(f[mi] - f[i - 1] <= t) ans = max(ans, (mi - i) + 1), lo = mi + 1;
            else hi = mi - 1;
        }
    }
}

int main () {

    scanf("%d %d", &n, &t);
    f[0] = 0;
    for(int i=1;i<=n;i++) scanf("%d", &x), f[i] = f[i - 1] + x;
    solve();
    printf("%d\n", ans);

    return 0;
}

