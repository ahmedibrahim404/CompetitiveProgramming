#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
const int MAX=10000+3;
int n;
vvi ns;

pi bfs(int node){

    queue<int> q;
    q.push(node);
    int dis[MAX];
    bool vis[MAX];
    for(int i=0;i<n;i++) vis[i]=0, dis[i]=1e9;
    dis[node]=0;vis[node]=1;int mx=0, noo=0;
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(int to: ns[cur]){
            if(vis[to]) continue;
            vis[to]=1;
            dis[to]=dis[cur]+1;
            q.push(to);
            if(dis[to] > mx) mx=dis[to], noo=to;
        }

    }

    return {mx, noo};

}

int main(){
    scanf("%d",&n);
    ns=vvi(n);
    for(int i=0;i<n-1;i++){
            int a, b;
        scanf("%d%d",&a,&b);
        a--, b--;
        ns[a].push_back(b);ns[b].push_back(a);
    }
    printf("%d\n", bfs(bfs(0).second).first);
    return 0;
}
