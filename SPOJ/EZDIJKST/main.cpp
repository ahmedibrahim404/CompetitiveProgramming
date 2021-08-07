#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef vector<pi> vi;
typedef vector<vi> vvi;
const int N = 10000 + 3;
int t, n, m;
vvi ns;

int dijkstra(int src, int dest){

    priority_queue< pair<int, int> > q;
    q.push({0, src});
    int dis[N];
    for(int i=0;i<n;i++) dis[i]=1e9;

    while(q.size()){
        pi cur= q.top();q.pop();
        int node=cur.second, cost=-cur.first;
        dis[node]=cost;

        if(node == dest) return cost;

        for(pi to: ns[node]){
            int toNode=to.first, toCost=to.second;
            if(dis[toNode] < toCost + cost) continue;
            dis[toNode] = toCost + cost;
            q.push({-dis[toNode], toNode});
        }

    }

    return -1;

}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        ns=vvi(n);
        for(int i=0;i<m;i++){
            int a, b, c;
            scanf("%d%d%d",&a,&b,&c);
            a--, b--;
            ns[a].push_back({b, c});
        }
        int a, b;
        scanf("%d%d",&a,&b);
        a--, b--;
        int ans=dijkstra(a, b);
        if(ans == -1) printf("NO\n");
        else printf("%d\n", ans);
    }



    return 0;
}
