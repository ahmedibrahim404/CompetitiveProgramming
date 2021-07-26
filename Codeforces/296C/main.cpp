#include <bits/stdc++.h>
using namespace std;

#define accel ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define	pb push_back
#define	mp make_pair
#define	ll long long
const double PI = acos(-1);
const int MAX = 2e9 + 7;
const long long MOD = 1e18 + 7;

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	ll a[n + 1];

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	vector<pair<pair<int, int>, int> > v;

	for (int i = 0; i < m; i++)
	{
		int l, r, d;
		cin >> l >> r >> d;
		v.pb(mp(mp(l, r), d));
	}

	int b2[m + 2];
	for (int i = 0; i < m + 2; i++)
	{
		b2[i] = 0;
	}

	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;

		b2[x]++;
		b2[y + 1]--;
	}

	for (int i = 2; i <= m; i++)
	{
		b2[i] += b2[i - 1];
	}

	ll b1[n + 2];

	for (int i = 0; i < n + 2; i++)
	{
		b1[i] = 0;
	}

	for (int i = 1; i <= m; i++)
	{
		int l = v[i - 1].first.first;
		int r = v[i - 1].first.second;
		int d = v[i - 1].second;

		b1[l] += (1ll * b2[i] * d);
		b1[r + 1] -= (1ll * b2[i] * d);
	}

	for (int i = 2; i <= n; i++)
	{
		b1[i] += b1[i - 1];
	}

	for (int i = 1; i <= n; i++)
	{
		if (i != 1) cout << " ";
		cout << a[i] + b1[i];
	}
    return 0;
}
