#include <iostream>
using namespace std;
int n, s, p, q;
int ns[109][109];
int cs=1;
int main(){

    while(scanf("%d", &n) == 1 && n){

        for(int i=0;i<109;i++) for(int j=0;j<109;j++) ns[i][j]=1e8;

        scanf("%d", &s);
        s--;
        while(scanf("%d %d", &p, &q) == 2 && p && q){
            p--;
            q--;
            ns[p][q]=-1;
        }

        for(int k=0;k<n;k++){
                for(int j=0;j<n;j++){
                    if(ns[s][k] < 1e8 && ns[k][j] < 1e8){
                        ns[s][j] = min(ns[s][j], ns[s][k] + ns[k][j]);
                    }
                }
        }

        int mx=0, in=-1;
        for(int i=0;i<n;i++){
            if(-1*ns[s][i] > mx){
                mx =-1*ns[s][i], in=(i+1);
            }
            else if(-1*ns[s][i] == mx && (i+1) < in)
                in = (i+1);
        }

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", cs++, (s+1), mx, in);
    }

    return 0;
}
