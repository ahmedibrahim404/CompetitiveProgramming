#include <iostream>

using namespace std;

int g1[500][500], g2[500][500], n, m;
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d", &g1[i][j]);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d", &g2[i][j]);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            int cur=g1[i][j];
            bool f=false;
            int i1=i, i2=j;
            while(i1 < n && i2 >= 0){
                if(g2[i1][i2] == cur){
                    g2[i1][i2]=-1;
                    f=true;
                    break;
                }
                i1++, i2--;
            }

            i1=i, i2=j;
            if(!f){

                while(i1 >= 0 && i2 < m){
                    if(g2[i1][i2] == cur){
                        g2[i1][i2]=-1;
                        f=true;
                        break;
                    }
                    i1--, i2++;
                }

            }

            if(!f){
                return printf("NO\n"), 0;
            }

        }
    }

    printf("YES\n");

    return 0;
}
