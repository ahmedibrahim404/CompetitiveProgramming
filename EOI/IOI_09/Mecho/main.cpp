#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> pii;
int n, s;
ii from, to;
queue<pii> qu;
char ns[800][800];
int nums[800][800];
int xs[]={1, -1, 0, 0}, ys[] = {0, 0, 1, -1};
void preProcess(){

    while(!qu.empty()){

        pii no=qu.front();qu.pop();
        int x=no.first.first, y=no.first.second, u=no.second;
        nums[x][y]=u;
        for(int i=0;i<4;i++){
            int nx=x+xs[i], ny=y+ys[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < n && nums[nx][ny] == 0 && ns[nx][ny] == 'G'){
                qu.push( make_pair( ii(nx, ny), u+1 ) );
                nums[nx][ny] = -1;

            }
        }

    }

}

int main(){
    scanf("%d %d", &n, &s);

    for(int i=0;i<n;i++){
        scanf("%s", ns[i]);
        for(int j=0;j<n;j++){
            if(ns[i][j] == 'M') from.first=i, from.second=j, ns[i][j]='G';
            else if(ns[i][j] == 'D') to.first=i, to.second=j;
            else if(ns[i][j] == 'H') qu.push(make_pair(ii(i, j), 0));
        }
    }

    preProcess();

    cout << nums[3][0] << endl;

    return 0;
}
