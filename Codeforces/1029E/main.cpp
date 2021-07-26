#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
int n, ans;
const int M =2e5 ;
vector<int> adj[M];
set<pair<int,int>> bad ;
int Par[M];
int dist[M];
void dfs (int u =0 , int dep =0 , int p = -1 )
{
    Par[u]  = p ;
    dist[u] = dep;
    for (int i : adj[u])
    {
       if (i == p)continue;
       dfs(i,dep+1,u);
    }
}
int main()
{
    cin >> n ;
    for (int i= 1 ; i < n ;i++)
    {
        int u, v ;
        cin >> u >> v ;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    for (int i =0 ; i < n ;i++)
        if (dist[i] > 2 )
            bad.insert({-dist[i],i});
    while (!bad.empty())
    {
        int cur = (*bad.begin()).s;
        bad.erase(bad.begin());
        cur = Par[cur];
        auto it = bad.find({-dist[cur] , cur});
        if (it != bad.end())
            bad.erase(it);
        ans++;
        for (int i : adj[cur]){
        auto it = bad.find({-dist[i],i});
        if (it != bad.end())
        bad.erase(it);
        }
    }
    cout << ans  <<"\n";
}
