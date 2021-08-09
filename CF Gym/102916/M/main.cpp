#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;
const int M = 1e9 + 7;

int n;
int u, v;

vector<int> adj[N];

vector<int> dp_mx[N];
vector<int> dp_mn[N];

pair<int, int> godfs_1(int cur = 0, int prev = -1) {
    pair<int, int> ret = {cur, cur};

    for (auto ver : adj[cur])
        if (ver != prev) {
            auto dfs = godfs_1(ver, cur);

            dp_mx[cur].push_back(dfs.first);
            dp_mn[cur].push_back(dfs.second);

            ret.first = max(ret.first, dp_mx[cur].back());
            ret.second = min(ret.second, dp_mn[cur].back());
        }

    return ret;
}

void godfs_2(int cur = 0, int prev = -1, int childNum = -1) {
    if (~prev) {
        int retMax = prev;
        int retMin = prev;
        for (int i = 0; i < dp_mx[prev].size(); i++) {
            if (i != childNum) {
                retMax = max(retMax, dp_mx[prev][i]);
                retMin = min(retMin, dp_mn[prev][i]);
            }
        }

        dp_mx[cur].push_back(retMax);
        dp_mn[cur].push_back(retMin);
    }

    for (int i = 0, cnt = 0; i < adj[cur].size(); i++)
        if (adj[cur][i] != prev)
            godfs_2(adj[cur][i], cur, cnt++);
}

map<int, bool> vis[N];

void prevent_dfs(int node, int par) {
    if (vis[node][par]) return;

    vis[node][par] = 1;
    for (auto i : adj[node])
        if (i != par)
            prevent_dfs(i, node);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;

    if (n == 1)
        return cout << "1\n", 0;

    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());

        int m = adj[i].size();

        if (m > 3)
            return cout << -1, 0;

        if (m == 3) {
            if (adj[i][0] > i || adj[i][2] < i)
                return cout << -1, 0;
        }

        if (m > 1) {
            if (adj[i][0] > i && adj[i][1] > i) {
                prevent_dfs(i, max(adj[i][0], adj[i][1]));
            } else if (adj[i][0] < i && adj[i][1] < i) {
                prevent_dfs(i, min(adj[i][0], adj[i][1]));
            }

            if (adj[i][m - 1] > i && adj[i][m - 2] > i) {
                prevent_dfs(i, max(adj[i][m - 1], adj[i][m - 2]));
            } else if (adj[i][m - 1] < i && adj[i][m - 2] < i) {
                prevent_dfs(i, min(adj[i][m - 1], adj[i][m - 2]));
            }
        }
    }

    godfs_1();
    godfs_2();

    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (vis[i].empty()) {
            if (adj[i].size() == 1) {
                if (dp_mx[i][0] < i) ans.push_back(i);
                if (dp_mn[i][0] > i) ans.push_back(i);
            } else if (adj[i].size() == 2) {
                if (dp_mx[i][0] < i && i < dp_mn[i][1]) ans.push_back(i);
                if (dp_mx[i][1] < i && i < dp_mn[i][0]) ans.push_back(i);
            }
        }

    if (ans.empty()) {
        return cout << -1 << endl, 0;
    }

    for (auto i : ans)
        cout << i + 1 << ' ';
    return 0;
}
