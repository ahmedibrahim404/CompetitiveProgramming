#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;
#define MAX 10010
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { numSets--;
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};


int qt_vertex, qt_edges;

int main() {
  int cases, u, v, w;
  scanf("%d", &cases);

  while (cases--){
      vector< pair<int, ii> > EdgeList;
      scanf("%d %d", &qt_vertex, &qt_edges);

      for (int i =0; i<qt_edges; i++){
       scanf("%d %d %d", &u, &v, &w);
       EdgeList.push_back(make_pair(-w, ii(u, v)));
      }
      sort(EdgeList.begin(), EdgeList.end());
      int E = EdgeList.size();
      UnionFind UF(qt_vertex+1);
      int ans = 0;
      for (int j = 0; j < E; j++) {
       pair<int, ii> front = EdgeList[j];
       int a,b;
       a = front.second.first;
       b = front.second.second;
       if (!UF.isSameSet(a, b) )
         UF.unionSet(a, b);
       else
          ans += -front.first;
      }
      printf("%d\n", ans);
  }
  return 0;
}
