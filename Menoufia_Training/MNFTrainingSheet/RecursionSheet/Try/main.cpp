#include <iostream>

using namespace std;
bool vis[500];
int cur[500];

void perm(int i=0, int n=5){

    if(i==n){
        for(int k=0;k<n;k++){
            printf("%d ", cur[k]);
        }
        printf("\n");
        return;
    }

    for(int j=1;j<=n;j++){
        if(!vis[j]){
            vis[j]=1;
            cur[i]=j;
            perm(i+1, n);
            vis[j]=0;
        }
    }
}

int main(){
    perm(0, 5);
    return 0;
}
