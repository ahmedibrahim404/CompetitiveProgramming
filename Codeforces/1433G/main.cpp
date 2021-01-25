#include<bits/stdc++.h>

using namespace std;
typedef vector<pair<int, int>> vi;
typedef vector<vi> vvi;
int n, m, k;
int dis[1000+3][1000+3];
vvi ns;
void bfs(int node){

    queue<int> q;
    q.push(node);
    dis[node][node]=0;
    int parent[1000+3];
    for(int i=0;i<n;i++) parent[i]=-1;
    parent[node]=node;

    while(!q.empty()){
        int cur=q.front();q.pop();
        for(pair<int, int> tonode:ns[cur]){
            int to=tonode.first, cost=tonode.second;
            if(to == parent[cur]) continue;
            if(dis[node][to] > dis[node][cur]+cost){
                dis[node][to] = dis[node][cur] + cost;
                parent[to]=cur;
                q.push(to);
            }
        }
    }

}

int main(){
    cin >> n >> m >> k;
    vector<pair<int, int>> routes, vi;
    int a, b,c;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dis[i][j]=1e9;
        }
    }

    ns=vvi(n);
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        a--, b--;
        ns[a].push_back({b, c});
        ns[b].push_back({a, c});
        routes.push_back({a, b});
    }

    for(int i=0;i<n;i++){
        bfs(i);
    }

    for(int i=0;i<k;i++){
        cin >> a >> b;
        a--, b--;
        vi.push_back({a, b});
    }

    int lst=1e9;

    for(auto pr: routes){
        int cost=0;
        int u=pr.first, v=pr.second;
        for(int i=0;i<k;i++){
            int fr=vi[i].first, to=vi[i].second;


            cost  += min( dis[fr][to], min( dis[u][fr] + dis[to][v], dis[u][to] + dis[fr][v] ) );

        }

        lst=min(lst, cost);
    }

    cout << lst << "\n";


    return 0;
}
