#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi ns;
int n, m;

int main(){
    scanf("%d%d",&n,&m);
    ns=vvi(n);
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        a--, b--;
        ns[a].push_back(b);ns[b].push_back(a);
    }

    int dis[n], parent[n];
    for(int i=0;i<n;i++) dis[i]=-1;
    queue<int> q;
    dis[0]=0, parent[0]=-1;
    q.push(0);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int to: ns[node]){
            if(dis[to]!=-1) continue;
            dis[to]=dis[node]+1;
            parent[to]=node;
            q.push(to);
        }
    }

    printf("%d\n", dis[n-1]-1);


    return 0;
}
