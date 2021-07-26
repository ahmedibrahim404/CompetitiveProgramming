#include <iostream>

using namespace std;

char ns[11][11];
int t, n;

bool can(int x, int y, char s){
    if(x+1<n && ns[x+1][y] == s) return false;
    if(x-1>=0 && ns[x-1][y] == s) return false;
    if(y-1>=0 && ns[x][y-1] == s) return false;
    if(y+1<n && ns[x][y+1] == s) return false;
    return true;
}

int main(){
    scanf("%d", &t);
    int cs=1;
    while(t--){
        scanf("%d", &n);

        for(int i=0;i<n;i++) scanf("%s", ns[i]);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ns[i][j] != '.') continue;
                for(char x='A';x<='Z';x++){
                    if( can(i, j, x) ) {ns[i][j]=x; break;}
                }
            }
        }

        printf("Case %d:\n", cs++);
        for(int i=0;i<n;i++) printf("%s\n", ns[i]);

    }
    return 0;
}
