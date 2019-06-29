#include<bits/stdc++.h>
using namespace std;

int const maxn = 60;
int const dr[] = {0, 0, -1, 1};
int const dc[] = {-1, 1, 0, 0};

int n;
char flat[maxn][maxn];
bool vis[maxn][maxn];
vector<pair<int, int> > V1, V2;

int dis(pair<int, int> x, pair<int, int> y) {
  int a = x.first - y.first;
  int b = x.second - y.second;
  return a*a + b*b;
}


void dfs(int r, int c, vector<pair<int, int> > &V) {
  for(int d = 0; d < 4; d++) {
    int nr = r+dr[d];
    int nc = c+dc[d];
    if(nr <= 0 || nc <= 0 || nr > n || nc > n || vis[nr][nc] || flat[nr][nc] == '1') continue;
    vis[nr][nc] = true;

    V.push_back({nr, nc});
    dfs(nr, nc, V);
  }
}

int main()
{

  int r1, r2, c1, c2;
  scanf("%d", &n);
  scanf("%d%d%d%d", &r1, &c1, &r2, &c2);

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) scanf(" %c", &flat[i][j]);

  memset(vis, false, sizeof vis);
  vis[r1][c1] = true;
  V1.push_back({r1, c1});
  dfs(r1, c1, V1);

  memset(vis, false, sizeof vis);
  vis[r2][c2] = true;
  V2.push_back({r2, c2});
  dfs(r2, c2, V2);

  int mini = 50*50*2;
  for(int i = 0; i < V1.size(); i++)
    for(int j = 0; j < V2.size(); j++) {
      mini = min(mini, dis(V1[i], V2[j]));
    }

  printf("%d\n", mini);

  return 0;
}
