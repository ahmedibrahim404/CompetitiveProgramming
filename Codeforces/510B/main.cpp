#include <iostream>
#include<queue>
using namespace std;

int n, m;
char ns[51][51];
bool vs[51][51];
int xs[] = {1, -1, 0, 0};
int ys[] = {0, 0, -1, 1};
typedef pair<int, int> ii;
typedef pair<ii, ii> pii;


bool BFS(int x, int y){
    queue<pii> q;
    q.push(make_pair(ii(x, y), ii(-1, -1)));

    while(!q.empty()){
        pii no=q.front();
        q.pop();

        int nx=no.first.first, ny=no.first.second, nf1=no.second.first, nf2=no.second.second;

        if(vs[nx][ny]) return true;
        vs[nx][ny]=true;
        for(int i=0;i<4;i++){
            int newx=nx+xs[i], newy=ny+ys[i];
            if(newx >= 0 && newy >= 0 && newx < n && newy < m && ns[newx][newy] == ns[x][y] &&
                !(newx == nf1 && newy==nf2)) q.push(make_pair(ii(newx, newy), ii(nx, ny)));
        }

    }

    return false;

}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) scanf("%s", ns[i]);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vs[i][j] && BFS(i, j)){
                printf("Yes\n");
                return 0;
            }
        }
    }

    printf("No\n");

    return 0;
}
