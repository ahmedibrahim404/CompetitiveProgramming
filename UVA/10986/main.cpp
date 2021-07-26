#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair< int, int > pii;

const int MAX = 20010;
const int INF = 0x3f3f3f3f;

vector< pii > G[MAX];
int d[MAX];

void dijkstra(int start) {
    int u, v, i, c, w;

    priority_queue< pii, vector< pii >, greater< pii > > Q;

    memset(d, INF, sizeof d);
    Q.push(pii(0, start));
    d[start] = 0;

    while(!Q.empty()) {
        u = Q.top().second;
        c = Q.top().first;
        Q.pop();

        if(d[u] < c) continue;

        for(i = 0; i < G[u].size(); i++) {
            v = G[u][i].first;
            w = G[u][i].second;


            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Q.push(pii(d[v], v));
            }
        }
    }
}

int main() {
    int test, n, e, i, u, v, w, start, dist, kase = 0;
    scanf("%d", &test);
    while(test--) {

        scanf("%d %d %d %d", &n, &e, &start, &dist);

        for(i = 0; i <= n; i++) G[i].clear();

        for(i = 0; i < e; i++) {
            scanf("%d %d %d", &u, &v, &w);
            G[u].push_back(pii(v, w));
            G[v].push_back(pii(u, w));
        }

        dijkstra(start);
        if(d[dist] == INF) printf("Case #%d: unreachable\n", ++kase);
        else printf("Case #%d: %d\n", ++kase, d[dist]);
    }
    return 0;
}
