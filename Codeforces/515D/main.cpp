#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
char a[2002][2002], tile[]="^<v>";
queue<pair<int,int> > q;

bool chk(int x, int y){
    return x<0||x>=n||y<0||y>=m?0:1;
}

void push(int x, int y){
    if(!chk(x, y)||a[x][y]!='.')return;
    int c=0;
    for(int i=0; i<4; i++){
        int X=x+dx[i], Y=y+dy[i];
        if(chk(X,Y)&&a[X][Y]=='.')c++;
    }
    if(c==0)cout << "Not unique", exit(0);
    if(c==1)q.push(make_pair(x, y));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];

        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            push(i,j);
            cnt+=(a[i][j]=='.');
        }
    }
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int X=x+dx[i], Y=y+dy[i];
            if(!chk(X,Y)||a[X][Y]!='.')continue;
            cnt-=2;
            a[x][y]=tile[(i+2)%4];
            a[X][Y]=tile[i];
            for(int j=0; j<4; j++){
                push(X+dx[j],Y+dy[j]);
            }
            break;

        }
    }
    if(cnt)cout << "Not unique";
    else{
        for(int i=0; i<n; i++)cout << a[i] << '\n';
    }
}
