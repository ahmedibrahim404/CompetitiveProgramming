#include <iostream>


using namespace std;
const int N = 1e5 + 5, M = 2 * N;

int n, m, SZ[N], par[N], hevChild[N], nodetoIdx[N], idxToNode[N], chain[N], depth[N], curTime;

void dfs(int u) {
    SZ[u] = 1;
    hevChild[u] = -1;
    nieg(adj, u, v, e) {
        if (v == par[u]) continue;
        par[v] = u;
        depth[v] = 1 + depth[u];
        dfs(v);
        if (hevChild[u] == -1 || SZ[hevChild[u]] < SZ[v])
            hevChild[u] = v;
        SZ[u] += SZ[v];

    }
}

void HLD(int u, int cId) {
    idxToNode[nodetoIdx[u] = curTime++] = u;
    chain[u] = cId;
    if (~hevChild[u])
        HLD(hevChild[u], cId);
    nieg(adj, u, v, e) {
        if (par[u] == v || hevChild[u] == v) continue;
        HLD(v, v);
    }
}

void updateRange(){
    // goes here SEG TREE
}

void update(int u, int v, int c) {
    while (chain[u] != chain[v]) {
        if (depth[chain[u]] < depth[chain[v]])
            swap(u, v);
        updateRange(nodetoIdx[chain[u]], nodetoIdx[u], c);
        u = par[chain[u]];
    }
    if (depth[u] < depth[v])
        swap(u, v);
    if (u != v)
        updateRange(nodetoIdx[v] + 1, nodetoIdx[u], c);
}


int main(){
    return 0;
}
