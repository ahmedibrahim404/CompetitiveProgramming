#include <iostream>

using namespace std;

int T, n, p;

int main(){

    scanf("%d", &T);

    while(T--){

        scanf("%d %d", &n, &p);
        int mx=2*n+p;

        for(int i=1;i<=n && mx > 0;i++){
            for(int j=i+1;j<=n && mx > 0;j++){
                printf("%d %d\n", i, j);
                mx--;
            }
        }

    }

    return 0;
}
