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


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);
#endif
    // freopen("input.txt", "r", stdin)

    ll t, n, n2;
    cin >> t;
    while (t--) {
        cin >> n;
        n2 = n;
        ll cnt = 0;
        while (n) {
            cnt += n % 2;
            n = n / 2;
        }
        ll ans = n2 + 1 - pow(2, cnt);
        cout << ans << endl;
    }
    return 0;
}
