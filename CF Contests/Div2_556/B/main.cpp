#include <iostream>

using namespace std;

int n, c=0;
char ns[51][51];
bool vis[51][51];

bool is(int i, int j){
    return ns[i][j] == '.' && !vis[i][j];
}

void visit(int i, int j){
    ns[i][j]=true;ns[i+1][j]=true;ns[i+2][j]=true;ns[i+1][j+1]=true;ns[i+1][j-1]=true;
}

int DFS(int i, int j){
    if(i >= n || j >= n || i < 0 || j < 0) return 0;
    int cnt=0;

    if(is(i, j) && is(i+1, j) && is(i+2, j) && is(i+1, j+1) && is(i+1, j-1)){
        cnt+=5;
        visit(i, j);
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                if(is(x, y)){
                    cnt += DFS(x, y);
                }
            }
        }
    }

    return cnt;

}

int main(){

    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%s", ns[i]);
        for(int j=0;j<n;j++){
            if(ns[i][j] == '.') c++;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ns[i][j] == '.'){
                for(int i=0;i<51;i++) for(int j=0;j<51;j++) vis[i][j]=false;
                if(DFS(i, j) == c){
                    printf("YES\n");
                    return 0;
                }
            }
        }
    }

    printf("NO\n");

    return 0;
}
