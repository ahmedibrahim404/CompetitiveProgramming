#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
// euler tour

const int N = 2000000 + 3, SZ = 4 * N;

vvi ns;vi v;
int n;
int nodeToIndex[N], indexToNode[N], dfn, depth[N];

int stTime[N], enTime[N], curTime;

void dfs(int u, int par){
    indexToNode[dfn]=u;
    nodeToIndex[u]=dfn++;
    for (int v: ns[u]){
        if (v == par) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        indexToNode[dfn++] = u;
    }
}

int sp[18][N], lg[N];
void buildSP(){
    lg[0] = -1;
    for (int i = 0; i < dfn; ++i){
        lg[i + 1] = lg[i] + !(i & (i + 1));
        sp[0][i] = i;
    }
    for (int j = 1; (1 << j) <= dfn; ++j){
        for (int i = 0; i + (1 << j) <= dfn; ++i){
            int a = sp[j - 1][i], b = sp[j - 1][i + (1 << (j - 1))];
            sp[j][i] = (depth[indexToNode[a]] < depth[indexToNode[b]] ? a : b);
        }
    }
}
int RMQ(int a, int b){
    int Log = lg[b - a + 1];
    a = sp[Log][a];
    b = sp[Log][b - (1 << Log) + 1];
    return (depth[indexToNode[a]] < depth[indexToNode[b]] ? a : b);
}
int LCA(int u, int v){
    u = nodeToIndex[u];
    v = nodeToIndex[v];
    if (u > v) swap(u, v);
    return indexToNode[RMQ(u, v)];
}



int main(){
    scanf("%d",&n);ns=vvi(n);
    for(int i=0;i<n-1;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        a--, b--;
        ns[a].push_back(b);ns[b].push_back(a);
    }
    depth[0]=0;
    dfs(0, -1);
    buildSP();

    int q;
    scanf("%d",&q);
    while(q--){
        int r, u, v;
        scanf("%d%d%d",&r, &u,&v);
        r--, u--, v--;
        int a = LCA(r,u);
        int b = LCA(r,v);
        int c = LCA(u,v);
        if(a==b) printf("%d\n", c+1);
        else if(b==c) printf("%d\n", a+1);
        else printf("%d\n", b+1);
    }

    return 0;
}
