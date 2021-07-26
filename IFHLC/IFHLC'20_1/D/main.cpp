#include <iostream>
#include <cstring>

using namespace std;
int t, n, ns[123], x1,y1,x2,y2;
int dis[123][83];

int DFS(int x, int y, string str=""){

    if(x==x2&&y==y2){
        return 0;
    }

    int &ret=dis[x][y];
    if(~ret) return ret;
    ret=2e9;

    int nx=x, ny=y+1;
    if(ny>ns[nx]) nx++, ny=0;
    if(nx <= n){
        ret=min(ret, DFS(nx, ny, str+"R"));
    }

    nx=x, ny=y-1;
    if(ny<0&&nx>1){
        nx--;ny=ns[nx];
    }
    if(ny>=0){ret=min(ret, DFS(nx, ny, str+"L"));}

    nx=x-1, ny=y;
    if(nx>=1){
        if(ny > ns[nx]) ny=ns[nx];
        ret=min(ret, DFS(nx, ny, str+"UP"));
    }

    nx=x+1, ny=y;
    if(nx<=n){
        if(ny > ns[nx]) ny=ns[nx];
        ret=min(ret, DFS(nx, ny, str+"D"));
    }

    ret++;

    return ret;


}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&ns[i]);
        for(int i=0;i<123;i++) for(int j=0;j<83;j++) dis[i][j]=-1;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n", DFS(x1, y1));


    }
    return 0;
}
