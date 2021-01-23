#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000 + 11;

int n, m;
int deg[N];
bool used[N];
vector<int> comp;
vector<int> g[N];

void dfs(int v) {
	used[v] = true;
	comp.push_back(v);

	for (auto to : g[v])
		if (!used[to])
			dfs(to);
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
		++deg[x];
		++deg[y];
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			comp.clear();
			dfs(i);
			bool ok = true;
			for (auto v : comp) ok &= deg[v] == 2;
			if(ok) ++ans;
		}
	}

	printf("%d\n", ans);

	return 0;
}
