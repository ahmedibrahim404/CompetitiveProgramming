#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, r, t[65][65], a[65][65][65];

int go(int k, int s, int e) {
	int &ret = a[k][s][e];
	if (ret != -1)
		return ret;
	ret = INT_MAX;
	for (int i = 1; i <= n; i++)
		ret = min(ret,go(k - 1, s, i) + a[0][i][e]);
	return ret;
}

int main() {
	cin >> n >> m >> r;
	memset(a, -1, sizeof a);
	for (int q = 0; q < m; q++) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> t[i][j];

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					t[i][j] = min(t[i][j], t[i][k] + t[k][j]);

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (a[0][i][j] == -1 || a[0][i][j] > t[i][j])
					a[0][i][j] = t[i][j];
	}
	while (r--) {
		int s, e, k;
		cin >> s >> e >> k;
		cout << go(min(n,k),s,e) << "\n";
	}
	return 0;
}
