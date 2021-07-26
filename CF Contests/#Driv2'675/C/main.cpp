#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{

    string s;
    cin >> s;

    int n = s.size();
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
    }

    const int MOD = (int)1e+9 + 7;

    ll ans = 0;
    ll sum = 0;
    ll p = 1;

    for (ll i = n - 1; i >= 0; --i) {
        ll k = (i * (i + 1) / 2 % MOD * p % MOD + sum) % MOD;
        sum = (sum + p * (n - i) % MOD) % MOD;
        p = p * 10 % MOD;
        ans = (ans + a[i] * k % MOD) % MOD;
    }

    cout << ans << endl;

    return 0;
}
