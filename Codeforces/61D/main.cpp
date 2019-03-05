#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 5;
vector<pair<int, int> > g[maxn];

long long dfs(int u, int par) {
	long long res = 0;
	for (int i = 0; i < g[u].size(); i++) {
		if (g[u][i].first != par) {
			res = max(res, dfs(g[u][i].first, u) + g[u][i].second);
		}
	}
	return res;
}

int main(void) {
	int n;
	scanf("%d", &n);
	long long res = 0;
	for (int i = 1; i < n; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
		res += 2 * w;
	}

	printf("%I64d", res - dfs(1, 0));

	return 0;
}
