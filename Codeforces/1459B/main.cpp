#include<bits/stdc++.h>

using namespace std;
const int MAX=2000+3;
typedef pair<int, int> pi;
int n;
bool vis[MAX][MAX];
bool stop[MAX][MAX];
int xs[] = {1, -1, 0, 0};
int ys[] = {0, 0, -1, 1};
void bfs(int x, int y, int lst, int len){
    if(vis[x][y]) return;
    vis[x][y]=1;
    if(len==n){
        stop[x][y]=1;
        return;
    }
    for(int i=0;i<4;i++){
        if(lst==i) continue;
        dfs(x+xs[i], y+ys[i], i, len+1);
    }
}
int main(){
    scanf("%d",&n);
    int x=500,y=500;
    memset(vis, 0, sizeof vis);
    memset(stop, 0, sizeof stop);

    dfs(501, 501, 4, 0);
    int cnt=0;
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            if(stop[i][j]){
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
