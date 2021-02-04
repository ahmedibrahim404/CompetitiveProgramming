#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int MAX=10000+3;
vvi ns;
int n, m, tot=0;
bool vis[MAX];
void dfs(int node, int par){
    if(vis[node]) return;
    vis[node]=1;
    for(int to: ns[node]){
        if(to==par) continue;
        dfs(to, node);
    }
    tot ++;
}

int main(){
    cin >> n >> m;
    ns=vvi(n);
    memset(vis, 0, sizeof vis);
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        ns[a].push_back(b);
        ns[b].push_back(a);
    }

    if(m+1 != n){
        cout << "NO\n";
        return 0;
    }

    dfs(0, -1);

    if(tot==n) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
