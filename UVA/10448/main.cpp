#include <bits/stdc++.h>
using namespace std;

#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define clr(v, d)		memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
typedef long long ll;

const int OO = 10000000;

int targetNode;


const int MAX = 50 + 9;
int path_backtrack[MAX][MAX];
int sp_cost[MAX][MAX];
int orig_cost[MAX][MAX];
vector<int> path_nodes;
vector<int> path_costs;

int memo[MAX][100000+9];

void build_sp_path(int src, int dest) {
	if (src != dest) {
		int prev = path_backtrack[src][dest];
		build_sp_path(src, prev);
		path_costs.push_back(orig_cost[prev][dest]);
	}
	path_nodes.push_back(dest);
}

void initialize(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sp_cost[i][j] = OO;
			path_backtrack[i][j] = i;	// from i to j directly no middle..
		}
		sp_cost[i][i] = 0;
	}
}

void floyd(int n) {
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (sp_cost[i][j] > sp_cost[i][k] + sp_cost[k][j]) {
					path_backtrack[i][j] = path_backtrack[k][j];
					sp_cost[i][j] = sp_cost[i][k] + sp_cost[k][j];
				}
}

int MinRoads(int idx, int remCost)
{
	if (remCost == 0)
		return 0;

	if (remCost < 0 || idx == (int)path_costs.size())
		return OO;

	int &ans = memo[idx][remCost];

	if(ans != -1)
		return ans;

	return ans = min(MinRoads(idx+1, remCost),
			         2 + MinRoads(idx, remCost - 2*path_costs[idx]));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.txt", "rt", stdin);
#endif

	int cases;
	cin >> cases;

	while (cases--) {
		int n, links, qu, a, b, c;

		cin >> n >> links;

		initialize(n);

		while (links--) {
			cin >> a >> b >> c;
			--a, --b;

			sp_cost[a][b] = sp_cost[b][a] = orig_cost[a][b] = orig_cost[b][a] = c;
		}

		floyd(n);

		cin >> qu;
		while (qu--) {
			cin >> a >> b >> c;
			a--, b--, targetNode = b;

			path_nodes.clear(), path_costs.clear();
			build_sp_path(a, b);
			path_nodes.pop_back(), path_costs.pop_back();

			c -= sp_cost[a][b];

			for (int i = 0; i < (int)path_costs.size(); ++i) {
				for (int j = 0; j <= c; ++j)
					memo[i][j] = -1;
			}
			int res = path_nodes.size() + MinRoads(0, c);


			if (res < OO)
				cout << "Yes " << res << "\n";
			else
				cout << "No\n";
		}
// Put a blank line between two consecutive sets of inputs.
			cout << "\n";
	}
	return 0;
}
