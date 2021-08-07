#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5, M = 1e4 + 4;
int n, T, dis[N], mark[M], m, l, st, en;
vector <pair <int, int>> adj[N];
set <pair <int, int>> s;

struct edge {
	int u, v, w;
} e[M];

void dij() {
	memset(dis, 63, sizeof dis);
	for (s.insert({dis[st] = 0, st}); s.size(); s.erase(s.begin())) {
		auto [d, u] = *s.begin();
		for (auto [v, i]: adj[u])
			if (dis[v] > d + e[i].w) {
				s.erase({dis[v], v});
				s.insert({dis[v] = d + e[i].w, v});
			}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> l >> st >> en;
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		if (!e[i].w)
			e[i].w = mark[i] = 1;
		adj[e[i].u].push_back({e[i].v, i});
		adj[e[i].v].push_back({e[i].u, i});
	}
	dij();
	if (dis[en] > l)
		return cout << "NO" << endl, 0;
	for (int i = 0; i < m; i++)
		if (mark[i]) {
			e[i].w += l - dis[en];
			dij();
		}
	if (dis[en] < l)
		return cout << "NO" << endl, 0;
	cout << "YES" << endl;
	for (int i = 0; i < m; i++)
		cout << e[i].u << ' ' << e[i].v << ' ' << e[i].w << endl;
}
