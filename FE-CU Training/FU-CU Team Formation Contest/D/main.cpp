#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MAX=123+1;
int t, n, ns[MAX], xx, yy, x2, y2;
int dis[MAX][MAX];
bool vis[MAX][MAX];
void bfs(){

    queue<pi> q;
    q.push(pi(xx, yy));
    dis[xx][yy]=0;

    while(!q.empty()){
        pi node=q.front();q.pop();
        int curx=node.first,cury=node.second;
        vis[curx][cury]=1;


//        cout << curx << " AND " << cury << endl;

        int nx=curx, ny=cury+1;
        if(ny>ns[nx]) nx++, ny=0;
        if(nx <= n && !vis[nx][ny]){
            q.push(pi(nx, ny));
            vis[nx][ny]=1;
            dis[nx][ny]=dis[curx][cury]+1;
            // Right
        }

        nx=curx, ny=cury-1;
        if(ny<0&&nx>1){
            nx--;ny=ns[nx];
        }

        if(ny>=0 && !vis[nx][ny]){
            q.push(pi(nx, ny));
            vis[nx][ny]=1;
            dis[nx][ny]=dis[curx][cury]+1;
        }

        nx=curx-1, ny=cury;
        if(nx>=1){
            if(ny > ns[nx]) ny=ns[nx];

            if(!vis[nx][ny]){
            q.push(pi(nx, ny));
            vis[nx][ny]=1;
            dis[nx][ny]=dis[curx][cury]+1;
            }
        }

        nx=curx+1, ny=cury;
        if(nx<=n){
            if(ny > ns[nx]) ny=ns[nx];

            if(!vis[nx][ny]){
            q.push(pi(nx, ny));
            vis[nx][ny]=1;
            dis[nx][ny]=dis[curx][cury]+1;
            }
        }

    }

}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        memset(vis, 0, sizeof vis);
        memset(dis, 0, sizeof dis);
        for(int i=1;i<=n;i++){
            cin >> ns[i];
        }
        cin >> xx >> yy >> x2 >> y2;
        bfs();
        cout << dis[x2][y2] << endl;
    }
    return 0;
}
