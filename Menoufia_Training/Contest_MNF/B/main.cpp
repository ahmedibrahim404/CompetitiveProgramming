#include <iostream>

using namespace std;

int T, n, k;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        if(n-k<=1){
            if((n-1)%2==1)
            printf("Ayoub\n");
            else printf("Kilani\n");
        }
        else printf("Kilani\n");
    }

    return 0;
}
