#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int q;
vvi adj;
int n, l;
int timer;
vi tin, tout;
vvi up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

vi lca(int u, int v)
{
    vi ns;
    if (is_ancestor(u, v)){
        ns.push_back(u);
        return ns;
    }
    if (is_ancestor(v, u)){
        ns.push_back(v);
        return ns;
    }
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)){
            ns.push_back(u);
            u = up[u][i];
        }
    }
    ns.push_back(up[u][0]);
    return ns;
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}




int a, b;
int main(){

    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

    cin >> n;
    adj=vvi(n);
    for(int i=0;i<n-1;i++){
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    preprocess(0);

    cin >> q;

    int c;
    while(q--){
        cin >> a >> b >> c;
        a--, b--;
        vi ans=lca(a, b);


    }



    return 0;
}
