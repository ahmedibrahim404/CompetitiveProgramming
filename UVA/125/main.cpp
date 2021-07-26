#include<bits/stdc++.h>
using namespace std;

int ns[51][51], n, a, b;
int main(){

    while(scanf("%d", &n) == 1){
        int mx=0;
        memset(ns, 0, sizeof(ns));
        for(int i=0;i<n;i++){
            scanf("%d %d", &a, &b);
            ns[a][b]=1;
            mx=max(mx, max(a, b));
        }

        mx++;
        for(int i=0;i<mx;i++) for(int j=0;j<mx;j++) if(ns[i][j] && ns[j][i]) ns[i][j]=-1;

        for(int k=0;k<mx;k++) for(int i=0;i<mx;i++) for(int j=0;j<mx;j++){
            if(ns[i][k] && ns[k][j]){
                if(ns[i][k] == -1 || ns[k][j] == -1) ns[i][j]=-1;
                else ns[i][j]+=ns[i][k]*ns[k][j];
            }
        }

        for(int i=0;i<mx;i++){
            for(int j=0;j<mx;j++) printf("%d ", ns[i][j]);
            printf("\n");
        }

    }

    return 0;
}
