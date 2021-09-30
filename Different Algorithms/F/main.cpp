#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi ns;
int n;

void bfs(int node){

    queue<int> q;
    vector<bool> vis(n, 0);
    vector<bool> dis(n, 0);
    q.push(0);
    int mx=0;
    while(!q.empty()){
        int to=q.front();
        q.pop();
        vis[to]=1;
        int sz=ns[to].size();
        for(int i=0;i<sz;i++){
            int nw=ns[to][i];
            if(vis[nw]) continue;
            vis[nw]=1;
            dis[nw]=dis[to]+1;
            mx=max(mx, dis[nw]);
            q.push(nw);
        }
    }


}


int main(){
    scanf("%d",&n);
    ns=vvi(n);
    int a, b;
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
        a--, b--;
        ns[a].push_back(b);
        ns[b].push_back(a);
    }

    int node=bfs(0);




    return 0;
}
