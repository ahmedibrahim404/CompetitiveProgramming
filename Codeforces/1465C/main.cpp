#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi ns;
int t, n, m;
int nx[100000+3];
bool vis[100000+3];

bool dfs(int node, int par=-1){
    if(node==-1) return 0;
    if(vis[node]) return 1;
    vis[node]=1;

    for(int i=0;i<ns[node].size();i++){
        if(ns[node][i] != par && dfs(ns[node][i], node)) return 1;
    }

    return 0;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        ns=vvi(n);
        int st=-1;
        int c=0;
        for(int i=0;i<n;i++) nx[i]=-1;
        for(int i=0;i<m;i++){
            int a, b;
            scanf("%d%d",&a,&b);
            if(a==b) continue;
            c++;
            a--, b--;
            ns[a].push_back(b);
            ns[b].push_back(a);
        }

        memset(vis, 0, sizeof vis);
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            if(dfs(i)){
                c++;
            }
        }

        printf("%d\n", c);

    }
    return 0;
}
