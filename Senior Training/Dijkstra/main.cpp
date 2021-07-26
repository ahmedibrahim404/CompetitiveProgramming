#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<pi> vi;
typedef vector<vi> vvi;
const int N = 1000000 + 3;
int dis[N];
vvi ns;int n;
void dijksrta(int src){

    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push({0, src});
    memset(dis, 0x3f, sizeof dis);
    dis[src]=0;
    while(!q.empty()){
        int c=q.top().first, u=q.top().second;q.pop();
        if(c != dis[u]) continue;

        for(int i=0;i<ns[u].size();i++){
            int v = ns[u][i].first;
            if(dis[v] > ns[u][i].second + c ){
                dis[v] = ns[u][i].second + c;
                q.push({ dis[v], v });
            }
        }

    }




}

int main(){
    int m;
    scanf("%d%d",&m,&n);
    ns=vvi(n);
    while(m--){
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        u--,v--;
        ns[u].push_back({v, c});
        ns[v].push_back({u, c});
    }
    dijksrta(n-1);
    printf("%d\n",dis[0]);

}
