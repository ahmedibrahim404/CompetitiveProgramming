#include <iostream>

using namespace std;
int n;
int ns[1000+9][1000+9];
bool vis[1000+9][1000+9];
int sol[1000+9][1000+9];
int xs[] = {0, 1, 0, -1};
int ys[] = {1, 0, -1, 0};
bool valid(int a, int b){
    return (a<n&&b<n&&a>=0&&b>=0&&!vis[a][b]);
}
int a=0,b=0;
void solve(int x, int y, int state=0){
    vis[x][y]=1;
    sol[a][b]=ns[x][y];
    b++;
    if(b==n) b=0, a++;

    if(valid(x+xs[state], y+ys[state])) return solve(x+xs[state], y+ys[state], state);
    if(valid(x, y+1))return solve(x, y+1, 0);
    if(valid(x+1, y))return solve(x+1, y, 1);
    if(valid(x, y-1))return solve(x, y-1, 2);
    if(valid(x-1, y))return solve(x-1, y, 3);

}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        scanf("%d",&ns[i][j]);
    }
    solve(0,0);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++){
            printf("%d", sol[i][j]);
            if(j!=n-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
