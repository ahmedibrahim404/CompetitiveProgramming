#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
vector<vector<char>> ns;
vector<vector<bool>> vis;

bool is(int a, int b){
    return (a<n&&b<m&&a>=0&&b>=0);
}

int dfs(int curx, int cury){
    if(!is(curx,cury) || ns[curx][cury]=='*' || vis[curx][cury]) return 0;
    vis[curx][cury]=1;
    return 1 + dfs(curx+1, cury) + dfs(curx-1, cury) + dfs(curx, cury+1) + dfs(curx, cury-1);
}

int main(){
    scanf("%d%d",&n,&m);
    ns=vector<vector<char>>(n);
    vis=vector<vector<bool>>(n);
    for (int i =0 ; i < n ;i++){
        for (int j =0 ; j < m ;j++){
            char c;
            cin >> c ;
            ns[i].push_back(c);
            vis[i].push_back(0);
        }
    }
    scanf("%d%d",&x,&y);
    x--,y--;
    printf("%d", dfs(x,y));
    return 0;
}
