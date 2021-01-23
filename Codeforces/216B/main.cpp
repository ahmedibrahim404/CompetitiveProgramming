#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;
vector< vector< int > > ns;
bool vis[100+1];

bool DFS(int node, int par, int &cnt){

    if(vis[node]) return 1;

    vis[node] = true;

    for(int i=0;i<ns[node].size();i++){
        if(ns[node][i] != par){
            cnt++;
            if(DFS(ns[node][i], node, cnt))
                return 1;
        }
    }

    return 0;

}


int main(){

    scanf("%d %d",, &n, &m);
    ns = vector< vector<int> > (n);
    while(m--){
        scanf("%d %d", &a, &b);
        a--, b--;
        ns[a].push_back(b);
        ns[b].push_back(a);
    }

    int re=0;
    for(int i=0;i<n;i++){
        if(!vis[i]) {
            int cnt=0;
            if(DFS(i, -1, cnt)) re += (cnt % 2 == 1);
        }
    }

    if( (n - re) % 2 == 1)
        re++;

    printf("%d", re);

    return 0;
}
