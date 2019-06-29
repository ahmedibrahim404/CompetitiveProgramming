#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; ++i)

int n;

vector <array <int, 2>> a;

void check(int s1, int s2) {
    int d = a[s2][0] - a[s1][0];
    int del = (s1 == 0 && s2 == 1) ? -1 : (s1==0) ? a[1][1] : a[0][1];
    int i_pre = s2;
    rep(i, s2 + 1, n) {
        int d2 = a[i][0] - a[i_pre][0];
        if (d2 != d) {
            if (del != -1) {
                return;
            }
            del = a[i][1];
        } else {
            i_pre = i;
        }
    }
    if (del == -1) {
        del = a[0][1];
    }
    cout << del+1 << '\n';
    exit(0);
}

main() {
    cin >> n;
    a.resize(n);
    rep(i, 0, n) {
        scanf("%d", &a[i][0]);
        a[i][1] = i;
    }
    if (n <= 3) {
        puts("1");
        return 0;
    }
    sort(a.begin(), a.end());
    check(0, 1);
    check(0, 2);
    check(1, 2);
    puts("-1");
}
