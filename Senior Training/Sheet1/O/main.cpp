#include<bits/stdc++.h>

using namespace std;


int n, m;
char str[51][51];
bool vis[51][51];
bool valid(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}

void dfs(int x, int y){

    if(vis[x][y]) return;
    vis[x][y]=1;
    str[x][y]='V';

    if(valid(x+1, y) && str[x+1][y] == '.') dfs(x+1, y);
    if(valid(x+1, y) && str[x+1][y] == '#'){
        if(valid(x, y+1) && str[x][y+1] == '.') dfs(x, y+1);
        if(valid(x, y-1) && str[x][y-1] == '.') dfs(x, y-1);
    }

}

int main(){
    cin >> n >> m;
    memset(vis, 0, sizeof vis);
    for(int i=0;i<n;i++){
        cin >> str[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(str[i][j]=='V') dfs(i, j);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << str[i][j];
        }
        cout << "\n";
    }
    return 0;
}
