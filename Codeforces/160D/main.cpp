#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], b[N],cost[N], par[N], rnk[N], res[N], o[N];
string solv[] ={"none", "at least one", "any"};
int get(int i){return par[i] == i? i : par[i] = get(par[i]);}
bool merge(int x, int y){
  x = get(x);
  y = get(y);
  if(x == y)return 0;
  if(rnk[x]>rnk[y])swap(x, y);
  rnk[x]+=rnk[y];
  par[y] =x;
}
struct cmp{
  bool operator()(int a, int b){
    return cost[a] < cost[b];
  }
};
map<int, vector<int> >adj, ids;
map<int, int>ti;
set<int>mrk;
int cnt;
int dfs(int u){
  if(ti.count(u))return ti[u];
  int cur = ti[u] = cnt++;
  for(int i  = 0; i < adj[u].size(); i++){
    int v = adj[u][i];
    int idx = ids[u][i];
    if(mrk.count(idx))continue;
    mrk.insert(idx);
    int r = dfs(v);
    cur = min(r, cur);
    if(r > ti[u])res[idx] = 2; // if bridge
  }
  return cur;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> a[i] >> b[i] >> cost[i];
    a[i]--, b[i]--;
    o[i] = i;
  }
  sort(o, o+m, cmp());
  for(int i = 0;i < n; i++)
    par[i] = i;
  for(int i = 0; i < m;){
    int k = i;
    while(i < m && cost[o[i]] == cost[o[k]])i++;
    adj.clear();
    ids.clear();
    ti.clear();
    for(int  j = k; j < i; j++){
      int x = get(a[o[j]]);
      int y = get(b[o[j]]);
      if(x == y) {
        res[ o[j] ]=0;
        continue;
      }

      res[o[j]] = 1;
      adj[x].push_back(y);
      ids[x].push_back(o[j]);
      adj[y].push_back(x);
      ids[y].push_back(o[j]);
    }
    for(auto it : adj)dfs(it.first);

    for(int j = k; j < i; j++)
      merge(a[o[j]], b[o[j]]);
  }
  for(int i = 0; i < m; i++)
    cout << solv[res[i]] << '\n';


}
