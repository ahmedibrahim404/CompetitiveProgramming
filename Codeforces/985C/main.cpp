#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;

int n, k, l, m;
vector<li> a;

void read() {
	cin >> n >> k >> l;
	m = n * k;
	a.assign(m, 0);
	fore(i, 0, m)
		scanf("%lld", &a[i]);
}

inline void solve() {
	sort(a.begin(), a.end());
	int rg = int(upper_bound(a.begin(), a.end(), a[0] + l) - a.begin());

	if(rg < n) {
		puts("0");
		return;
	}
	li ans = 0;

	int u = 0;

	fore(i, 0, n) {
		ans += a[u++];

		fore(j, 0, k - 1) {
			if(rg - u > n - i - 1)
				u++;
			else
				break;
		}
	}

	cout << ans << endl;
}

int main() {
    read();
    solve();
	return 0;
}
