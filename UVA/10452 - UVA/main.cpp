#include <iostream>
#include<vector>
#include<cstring>
using namespace std;
const int MAX=31;
int T, n, m;
char ns[MAX][MAX];
bool vis[MAX][MAX];
int x1, y1, x2, y2;
string smn="IEHOVA#";

int xs[] = {0, 0, -1};
int ys[] = {1, -1, 0};
// up, right, left
bool is(int a, int b){
    return a>=0 && b>=0&& a<n && b<m;
}

vector<int> ans;

void dfs(int x, int y, int idx){
    if(vis[x][y]) return;
    vis[x][y]=1;
    if(ns[x][y]=='#') return;
    for(int i=0;i<3;i++){
        int nx=x+xs[i], ny=y+ys[i];
        if(is(nx, ny) && ns[nx][ny]==smn[idx] && !vis[nx][ny]){
            ans.push_back(i);
            dfs(nx, ny, idx+1);
        }
    }

}

int main(){
    cin >> T;
    while(T--){
        cin >> n >> m;
        ans.clear();
        memset(vis, 0, sizeof vis);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> ns[i][j];

            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ns[i][j]=='@'){
                    dfs(i, j, 0);
                    break;
                }

            }
        }

        for(int i=0;i<ans.size();i++){
            if(ans[i]==0) cout << "right";
            else if(ans[i]==1) cout << "left";
            else cout << "forth";
            if(i!=ans.size()-1) cout << " ";
        }
        cout << endl;

    }
    return 0;
}
