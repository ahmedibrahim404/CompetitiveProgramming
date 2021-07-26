#include <iostream>

using namespace std;
int Ra, Ca, Rb, Cb;
int na[101][101], nb[101][101], res[101][101];
bool vis[101][101];

void solve(int r, int c){
    if(r>= Ra || c >= Cb||vis[r][c]) return;
    for(int i=0;i<Ca;i++)res[r][c]+=na[r][i]*nb[i][c];
    vis[r][c]=1;
    solve(r+1, c);
    solve(r, c+1);
}

int main(){
    for(int i=0;i<101;i++) for(int j=0;j<101;j++) vis[i][j]=0;
    scanf("%d%d",&Ra,&Ca);
    for(int i=0;i<Ra;i++) for(int j=0;j<Ca;j++) scanf("%d",&na[i][j]);
    scanf("%d%d",&Rb,&Cb);
    for(int i=0;i<Rb;i++) for(int j=0;j<Cb;j++) scanf("%d",&nb[i][j]);

    solve(0, 0);
    for(int i=0;i<Ra;i++) {
        for(int j=0;j<Cb;j++){
            printf("%d", res[i][j]);
            if(j!=Cb-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
