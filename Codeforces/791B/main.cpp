#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int n, m,a,b;
ll nc, ec;
vvi ns;
bool vis[150000+3];
void DFS(int node){
    vis[node]=1;
    nc++;
    for(int i=0;i<ns[node].size();i++){
        if(!vis[ns[node][i]]){
            vis[ ns[node][i] ]=1;
            DFS(ns[node][i]);
        }
        ec++;
    }

}
int main(){
    scanf("%d %d",&n,&m);
    ns=vvi(n);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        a--, b--;
        ns[a].push_back(b);
        ns[b].push_back(a);
    }

    for(int i=0;i<n;i++) vis[i]=0;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            nc=0, ec=0;
            DFS(i);
            if(nc*(nc-1) != ec) return printf("NO"), 0;
        }
    }

    printf("YES");

    return 0;
}
