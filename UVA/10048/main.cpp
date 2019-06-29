#include <iostream>

using namespace std;

int C, S, Q, a, b, u, cs=1;
int ns[109][109];

int main(){

    while( scanf("%d %d %d", &C, &S, &Q) == 3 && C && S && Q){


        for(int i=0;i<C;i++) for(int j=0;j<C;j++) ns[i][j]=1e8;

        while(S--){
            scanf("%d %d %d", &a, &b, &u);
            a--, b--;
            ns[a][b]=u, ns[b][a]=u;
        }


        for(int k=0;k<C;k++) for(int i=0;i<C;i++) for(int j=0;j<C;j++) {
            if( ns[i][k] < 1e8 && ns[k][j] < 1e8 ){
                ns[i][j] = min( ns[i][j], max( ns[i][k], ns[k][j] ) );
            }
        }

        printf("Case #%d\n", cs++);
        while(Q--){
            scanf("%d %d", &a, &b);
            a--, b--;
            if(ns[a][b] == 1e8 && ns[b][a] == 1e8) printf("no path\n");
            else printf("%d\n", max(ns[a][b], ns[b][a]));

        }

        printf("\n");

    }

    return 0;
}
