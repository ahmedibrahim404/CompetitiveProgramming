#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int n, m, k;
char ns[501][501];
char str[501];
bool vis[501][501];
typedef pair<int, int> ii;

int xs[] = {1, -1, 0, 0};
int ys[] = {0, 0, -1, 1};

int BFS(int x, int y){

    queue<ii> q;
    q.push(ii(x, y));
    int no=0;

    while(!q.empty()){

        ii p=q.front();q.pop();
        int nx=p.first, ny=p.second;
        vis[nx][ny]=true;

        no++;
        for(int i=0;i<4;i++){
            int newx = nx+xs[i], newy=ny+ys[i];
            if(newx >= 0 && newy>=0 && newx < n && newy<m && !vis[newx][newy] && ns[newx][newy] == '.'){
                q.push(ii(newx, newy));
            }
        }

    }

    return no;

}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    int cnt=0;
    for(int i=0;i<n;i++){
        scanf("%s", str);
        for(int j=0;j<strlen(str);j++){
            ns[i][j] = str[j];
            if(ns[i][j] == '.') cnt++;
        }
    }

    int removed=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ns[i][j] == '.'){
                ns[i][j] = 'X';
                int cn=BFS(i, j);
                if(cn == cnt-removed-1){
                    k--;
                    removed++;
                } else ns[i][j] = '.';
                if(k == 0) break;
            }
        }
        if(k == 0) break;
    }

    for(int i=0;i<n;i++) cout << ns[i] << endl;


    return 0;
}
