#include <bits/stdc++.h>

using namespace std;

vector<int> ord;
vector<int> used;
vector<vector<int>> g;

void dfs(int v) {
	used[v] = 1;
	for (auto to : g[v]) {
		if (!used[to]) dfs(to);
	}
	ord.push_back(v);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		g = vector<vector<int>>(n);
		vector<pair<int, int>> edges;
		for (int i = 0; i < m; ++i) {
			int t, x, y;
			cin >> t >> x >> y;
			--x, --y;
			if (t == 1) {
				g[x].push_back(y);
			}
			edges.push_back({x, y});
		}

		ord.clear();
		used = vector<int>(n);
		for (int i = 0; i < n; ++i) {
			if (!used[i]) dfs(i);
		}
		vector<int> pos(n);
		reverse(ord.begin(), ord.end());
		for (int i = 0; i < n; ++i) {
			pos[ord[i]] = i;
		}
		bool bad = false;
		for (int i = 0; i < n; ++i) {
			for (auto j : g[i]) {
				if (pos[i] > pos[j]) bad = true;
			}
		}
		if (bad) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			for (auto [x, y] : edges) {
				if (pos[x] < pos[y]) {
					cout << x + 1 << " " << y + 1 << endl;
				} else {
					cout << y + 1 << " " << x + 1 << endl;
				}
			}
		}
	}

	return 0;
}
