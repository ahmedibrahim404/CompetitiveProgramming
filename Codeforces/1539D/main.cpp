#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 2e5 + 5;
ll n;
deque<pair<ll, ll>> q;
bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
    if(x.second != y.second)
        return x.second < y.second;
    return x.first > y.first;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++) {
        ll a, b;
        cin >> a >> b;
        q.push_back({a, b});
    }
    sort(q.begin(), q.end(), cmp);
    ll cnt = 0, ans = 0;
    while(q.size()) {
        if(q.back().first + cnt >= q.front().second) {
            ll tmp = q.front().second - cnt;
            cnt += tmp, ans += tmp * 2;
            q.back().first -= tmp;
            if(q.back().first == 0)
                q.pop_back();
            while(q.size() && q.front().second <= cnt) {
                ans += q.front().first;
                cnt += q.front().first;
                q.pop_front();
            }
        } else {
            cnt += q.back().first;
            ans += q.back().first * 2;
            q.pop_back();
        }
    }
    cout << ans;
    return 0;
}
