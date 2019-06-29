#include <iostream>

using namespace std;

int n, m;
int ns[109][109];
int res[109];
int a, b;

void getNot(int no){
    int cos=0;
    for(int i=0;i<n;i++){
        if(ns[no][i] >= 1e8){
            res[cos++]=(i+1);
        }
    }

    printf("%d", cos);
    for(int i=0;i<cos;i++) printf(" %d", res[i]);
    printf("\n");
}

int main(){

    while(scanf("%d", &n) == 1 && n){

        for(int i=0;i<109;i++) for(int j=0;j<109;j++) ns[i][j]=1e8;

        while(scanf("%d", &a) == 1&& a){
            a--;
            while(scanf("%d", &b) == 1 && b){
                b--;
                ns[a][b] = 1;
            }
        }

        for(int k=0;k<n;k++) for(int i=0;i<n;i++) for(int j=0;j<n;j++)
            ns[i][j] = min( ns[i][j], ns[i][k] + ns[k][j] );

        scanf("%d", &m);
        for(int i=0;i<m;i++){
            scanf("%d", &a);
            a--;
            getNot(a);
        }

    }

    return 0;
}
