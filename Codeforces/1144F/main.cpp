#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<list>
#include<stack>
#include<deque>
#include <string.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
using namespace std ;
int C[200001];
vector <int> adj[200001];
vector <pair<int,int>> ans ;
void color (int v  )
{
   for (int u : adj[v])
   {

       if (C[u] == C[v] )
       {
           printf ("NO\n") ;
           exit(0);
       }
       if (C[u] != -1 )continue ;
       C[u] = C[v] ^ 1;
       color(u);
   }
}
int n , m ;
int main ()
{
    scanf ("%d%d" , &n ,&m );
    for (int i =0 ; i < m ;i++)
    {
        int a, b ;
        scanf ("%d%d" , &a , &b );
        ans.pb({a,b});
        adj[a].pb(b);
        adj[b].pb(a);
    }
    memset (C , -1 , sizeof C );
    C[1] = 1 ;
    color(1);
      printf ("YES\n");
      for (int i =0 ; i < m ;i++)
      {
        if (C[ans[i].f]  > C[ans[i].s])
            printf ("1");
        else
            printf ("0");
      }
      printf ("\n");
    return 0;
}
