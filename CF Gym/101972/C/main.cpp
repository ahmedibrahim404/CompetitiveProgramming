#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll  long long int
#define ld long double

#define ordered_set tree<pair<ll ,int>, null_type,greater<pair<ll ,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define INF 1e18

using namespace std;
using namespace __gnu_pbds;

const long double pi = 3.141592653589793238;

ld err = 1e-9;

ld dist(ld a, ld b) {
    return sqrt(a * a + b * b);
}

ld fun(ld a, ld b, ld c) {
    ld A = sqrt((a) * (a) + ((b + 2 *c) * (b + 2*c)));
    return A;
}
int main() {
    ll t, n, n2;
    cin >> t;
    while (t--) {
        ld a, b, c, x;
        cin >> a >> b >> c >> x;
        x /= 100.0;
        ld ans = fun(a, b, c);

        ans += dist(a*x, b*x);
        a -= a * x;
        b -= b * x;
        ans += fun(a, b, c);

        cout << fixed << setprecision(10) << ans << endl;

    }
    return 0;
}
