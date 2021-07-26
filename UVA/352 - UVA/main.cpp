#include <iostream>
#include <cstring>
using namespace std;
const int MAX=26;
int n;
char ns[MAX][MAX];
bool vis[MAX][MAX];

bool is(int a, int b){
    return a>=0 && b>=0&& a<n && b<n && ns[a][b]=='1';
}

int xs[] = {1, -1, 0, 0, 1, -1, 1, -1};
int ys[] = {0, 0, 1, -1, 1, -1, -1, 1};

void dfs(int x, int y){

    vis[x][y]=1;
    for(int i=0;i<8;i++){
        int nx=x+xs[i], ny=y+ys[i];
        if(!is(nx, ny) || vis[nx][ny]) continue;
        dfs(nx, ny);
    }

}

int main(){
    int T=1;
    while(cin>>n){
        int cnt=0;
        memset(vis, 0, sizeof vis);
        for(int i=0;i<n;i++) cin >> ns[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ns[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << "Image number "<<T++<<" contains "<<cnt<<" war eagles." << endl;;
    }
    return 0;
}
