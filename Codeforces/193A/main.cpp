#include<bits/stdc++.h>
using namespace std;
const int N = 50 + 3;
int n, m;
int vis[N][N];
char ns[N][N];

int xx, yy;

bool valid(int x, int y){
    return x >= 0 && y >=0 && x < n && y < m && ns[x][y] == '#' && (x != xx || y != yy);
}

int tot=0;
int xs[] = {1, -1, 0, 0};
int ys[] = {0, 0, -1, 1};

void dfs(int x, int y, int pre){

    if(vis[x][y]) return;
    tot++;
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int nx=x+xs[i], ny=y+ys[i];
        if(valid(nx, ny) && (i^1) != pre){
            dfs(nx, ny, i);
        }
    }

}

int main(){
    cin >> n >> m;
    int cnt=0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) vis[i][j]=0;
    for(int i=0;i<n;i++){
        cin >> ns[i];
        for(int j=0;j<m;j++){
            if(ns[i][j] =='#') cnt++;
        }
    }

    if(cnt <= 2) {
        cout << "-1\n";
        return 0;
    }

    int ans=-1;

    for(int i=0;i<n;i++) {for(int j=0;j<m;j++){
        if(ns[i][j] == '#'){
            xx=i, yy=j;
            for(int k=0;k<4;k++){
                int ni = i+xs[k], nj=j+ys[k];
                if(valid(ni, nj)){
                    memset(vis, 0, sizeof vis);tot=0;
                    dfs(ni, nj, 4);
                    if(tot == cnt-1) break;
                    ans=1;
                }
            }
        }
        if(ans != -1) break;
    } if(ans != -1) break;
    }
    if(ans == -1) ans=2;

    cout << ans;



    return 0;
}
