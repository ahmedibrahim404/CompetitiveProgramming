#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<pi> vi;
typedef vector<vi> vvi;


// -ve costs
const int N = 1000000+3;
int inQ[N], dis[N];
int n;
vvi ns;

bool bellman(int src){

    queue<int> q; // for nodes changed last time
    memset(dis, 0x3f, sizeof dis);
    dis[src]=0;
    inQ[src]=1;

    int cnt=n; // how many nodes in path ( if > n then cycle )
    q.push(src);
    while(cnt-- && q.size()){
        int s=q.size();
        while(s--){
            int u=q.front();
            q.pop();
            inQ[u]=0;
            for(pi to: ns[u]){
                int v=to.first, c=to.second;
                int d=c+dis[u];
                if(dis[v] > d){
                    if(!cnt) return 0;// cycle detected
                    dis[v]=d;
                    if(!inQ[v]){
                        inQ[v]=1;
                        q.push(v);
                    }
                }
            }
        }

    }

    return true;

}

int main()
{

    int m;
    scanf("%d%d",&n,&m);
    ns = vvi(n);
    while(m--){
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        u--,v--;
        ns[u].push_back({v, c});
    }
    bellman( 0 );
    for ( int i = 0 ; i < n ; i ++ ){
        if ( dis[i] == 0x3f3f3f3f )
            printf ( "%d%c" , 30000 , " \n"[i==n-1] ) ;
        else
            printf( "%d%c" , dis[i] , " \n"[i==n-1]  ) ;

    }

}
