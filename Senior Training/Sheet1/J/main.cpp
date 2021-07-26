#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
	int n, m, u, v;
	vector<vi> ns;

	while (cin >> n && n) {
		ns = vector<vi>(n);
		cin >> m;

		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			ns[u].push_back(v);
			ns[v].push_back(u);
		}

		queue<int> q;
		q.push(0);
		vi color(n, 1e9);
		color[0] = 0;
		bool isBipartite = true;
		while (!q.empty() && isBipartite) {
			int u = q.front();
			q.pop();
			for (int j = 0; j < ns[u].size(); j++) {
				int v = ns[u][j];
				if (color[v] == 1e9) {
					color[v] = 1 - color[u];
					q.push(v);
				} else if (color[v] == color[u]) {
					isBipartite = false;
					break;
				}
			}
		}

		if (isBipartite)
			cout << "BICOLORABLE.\n";
		else
			cout << "NOT BICOLORABLE.\n";
	}

	return 0;
}
