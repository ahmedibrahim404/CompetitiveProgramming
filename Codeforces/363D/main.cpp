#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, m, a;
ll b[100000], p[100000];
ll check(ll k)
{
    ll total = 0;
    ll share = a;
    for (int i = n - k, j = 0; j < k; i++, j++)
    {
        if (b[i] < p[j])
        {
            share -= p[j] - b[i];
            total += b[i];
            if (share < 0)
                return -1;
        }
        else
            total += min(b[i], p[j]);
    }

    total -= min(total, share);
    return total;
}
int main()
{
    cin >> n >> m >> a;
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<m;i++) cin >> p[i];
    sort(b, b + n);
    sort(p, p + m);

    ll low = 0, high = min(n, m) + 1;
    while (high - low > 1)
    {
        ll mid = (low + high) / 2;
        ll t = check(mid);
        if (t == -1)
            high = mid;
        else
            low = mid;
    }
    ll r = low;
    ll s = check(r);
    cout << r << " " << s << endl;
}
