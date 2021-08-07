#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

int n, m;
const int N = 16;
const int MaskN = (1 << N) + 1;
int in[N];
int vis[N];
vector<int> adj[N];

ll tot;
ll dp[N][N];
ll dp2[MaskN];


void dfs(int u) {
  vis[u] = 1;
  for (int v : adj[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}

ll solve(ll mask) {
  if (mask == 0) return 0;
  ll &ret = dp2[mask];
  if (~ret) return ret;
  ret = 2e18;

  for (int i = 0; i < n; i++) {
    if (mask & (1 << i)) {
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        if (mask & (1 << j)) {
          ret = min(ret, solve(mask - (1 << i) - (1 << j)) + dp[i][j]);
        }

      }
    }
  }
  return ret;
}


int main() {
  cin >> n >> m;
  memset(dp, 0x3f, sizeof(dp));

  for (int i = 0; i < m; i++) {
    int u, v, c;

    cin >> u >> v >> c;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);

    tot += c;
    if (u != v) {
      dp[u][v] = dp[v][u] = min(dp[u][v], 1LL * c);
      in[u]++, in[v]++;
    }
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  dfs(0);
  for (int i = 0; i < n; i++) {
    if (adj[i].size() && !vis[i]) {
      cout << "-1" << endl;
      return 0;
    }
  }

  ll msk = 0;
  for (int i = 0; i < n; i++) {
    if (in[i] & 1) {
      msk |= (1 << i);
    }
  }
  memset(dp2, -1, sizeof(dp2));
  tot += solve(msk);
  cout << tot << endl;
}
