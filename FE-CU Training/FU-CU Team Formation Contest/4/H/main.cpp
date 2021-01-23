#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, int> pi1;
typedef pair<int, ll> pi2;

const int MAX=100000+3;
const ll OO=1e18;
ll dis[MAX], T[MAX];
vector<pi2> ns[MAX];
int n, m, k;

void dijkstra(){

    priority_queue<pi1,vector<pi1>,greater<pi1>> q;
    for(int i=0;i<n;i++){
        if(dis[i] != OO) q.push(pi1(dis[i], i));
    }

    while(!q.empty()){
        pi1 p = q.top();
        q.pop();

        int u = p.second;ll dist = p.first;
        if(dist > dis[u]) continue;

        for(pi2 pr : ns[u]){
            int v = pr.first;
            ll newdis = dist + pr.second + T[v];

            if(newdis < dis[v]){
                dis[v] = newdis;
                q.push({newdis,v});
            }
        }
    }

    for(int i=0;i<n;i++){
        printf("%lld\n", dis[i]);
    }

}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++) dis[i] = OO;

    for(int i=0;i<m;i++){
        int a, b;
        ll c;
        scanf("%d%d%lld",&a,&b,&c);
        a--, b--;
        ns[a].push_back(pi2(b, c));
        ns[b].push_back(pi2(a, c));
    }

    for(int i=0;i<n;i++) scanf("%lld",&T[i]);
    int no;

    for(int i=0;i<k;i++){
        scanf("%d",&no);
        no--;
        dis[no]=T[no];
    }

    dijkstra();



    return 0;
}
