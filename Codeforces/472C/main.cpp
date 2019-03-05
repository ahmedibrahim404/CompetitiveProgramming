#include <iostream>

using namespace std;

int n;
int ns[2001][2001];
int main(){

    scanf("%d", &n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d", &ns[i][j]);

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if((ns[i][j] != ns[j][i]) || (i != j && ns[i][j] == 0) || ( i == j && (ns[i][j] != 0 || ns[j][j] != 0)  )){
                printf("NO");
                return 0;
            }
        }
    }

    printf("YES");

    return 0;
}
