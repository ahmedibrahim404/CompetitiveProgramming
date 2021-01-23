#include <iostream>

using namespace std;
int n;
int ns[100+9][100+9];
bool vis[100+9][100+9];
int sol[100+9][100+9];
int xs[] = {0, 1, 0, -1};
int ys[] = {1, 0, -1, 0};
bool valid(int a, int b){
    return (a<n&&b<n&&a>=0&&b>=0&&!vis[a][b]);
}
int a=0,b=1;
void solve(int x, int y, int state=0){
    cout << x << " " << y << endl;
    vis[x][y]=1;
    sol[a][b]=ns[x][y];
    b++;
    if(b==n) b=0, a++;
    if(state==0){
        if(valid(x+1, y-1)) return solve(x+1, y-1, 0);
        else return solve(x+1, y, 1);
    } else {
        if(valid(x-1, y+1)) return solve(x-1, y+1, 1);
        else return solve(x, y+1, 0);
    }

}
int T;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) for(int j=0;j<n;j++){
            scanf("%d",&ns[i][j]);
            vis[i][j]=0;
            sol[i][j]=0;
        }
        vis[0][0]=1;
        sol[0][0]=ns[0][0];
        solve(0,1,0);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++){
                printf("%d", sol[i][j]);
                if(j!=n-1) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
