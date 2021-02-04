#include<bits/stdc++.h>

using namespace std;

const int N=2e5, M=2*N;

int n, m, ne;
int to[M], nxt[M], head[N];
bool vis[N];

void addEdge(int f, int t){
    to[ne]=t;
    nxt[ne]=head[f];
    head[f]=ne++;
}


void init(){
    cin >> n >> m;
    memset(head, -1, n * sizeof head[0]);
    memset(vis, 0, n * sizeof vis[0]);
    int a, b;
    while(m--){
        cin >> a >> b;
        a--, b--;
        addEdge(a, b);
        addEdge(b, a);
    }
}

void dfs(int u){
    if(vis[u]) return;
    vis[u]=1;
    for(int e=head[u]; e != -1; e=nxt[e]){
        int v=to[e];
        dfs(v);
    }
    cout << u << "\n";
}

int main(){
    init();
    dfs(0);
    return 0;
}
