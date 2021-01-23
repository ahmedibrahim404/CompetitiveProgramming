#include <iostream>

using namespace std;

int T, N, v, p;
int main(){

    scanf("%d", &T);

    while(T--){

        scanf("%d", &N);
        int mi=1e9;
        while(N--){
            scanf("%d %d", &p, &v);
            mi = min(mi, p-v);
        }

        printf("%d\n", mi);

    }

    return 0;
}
