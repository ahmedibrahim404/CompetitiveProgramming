#include <iostream>

using namespace std;

int n, m;
int ns[500][500], chosen[500];
int main(){

    scanf("%d %d", &n, &m);
    int ans=0;
    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){
            scanf("%d", &ns[i][j]);
        }

        chosen[i]=0;
        ans^=ns[i][0];

    }

    if(ans==0){

        bool stop=false;
        for(int i=0;i<n && !stop;i++){
            for(int j=0;j<m;j++){
                if(j != chosen[i] && ns[i][j] != ns[ i ][ chosen[i] ]) {
                    chosen[i]=j, stop=1;
                    ans=1;
                    break;
                }
            }
        }

    }

    if(ans == 0) printf("NIE\n");
    else {
        printf("TAK\n");
        for(int i=0;i<n;i++) printf("%d ", chosen[i]+1);
    }

    return 0;
}
