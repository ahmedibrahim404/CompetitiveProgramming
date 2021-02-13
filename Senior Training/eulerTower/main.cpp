#include<bits/stdc++.h>

using namespace std;

/**

    You need to visit all (((((edges))))) exactly one
    => Maybe start at some node and end at it
    or start at some one and end at another.

    ==> Undirected graphs ==> [[
        it can be proven that no. of odd-degree nodes is always (even)
        we can find such solution ( path in graph ) if and only if no. of odd-degree nodes == 0 OR 2
        if( equal 2 ) Start at any one of them
        if( equal 0 ) Start at any node
    ]]

**/
typedef vector<int> vi;
typedef vector<vi> vvi;
const int MAX=100000+3;
vvi ns;bool vis[MAX];
map<pair<int, int>, int> mp;

// NOTE:: YOU MUST VISIT EACH EDGE **ONCE** NOT EACH NODE

void eulerTower(int u, int par){

    pair<int, int> pi = {min(u, par), max(u, par)};
    if(vis[ mp[pi] ]) return;
    vis[ mp[pi] ]=1;
    for(int to: ns[u]){
        if(vis[ mp[ {min(to, u), max(to, u)} ] ]) continue;
        eulerTower(to, u);
    }

    cout << u << "\n";

}


int n, m;
int main(){
    scanf("%d%d",&n,&m);
    ns=vvi(n); memset(vis, 0, n * sizeof vis[0]);
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        a--, b--;
        mp[ {min(a, b), max(a, b)} ]=i;
        ns[a].push_back(b);ns[b].push_back(a);
    }

    mp[{0, 0}] = m;

    eulerTower(0, 0);


    return 0;
}
