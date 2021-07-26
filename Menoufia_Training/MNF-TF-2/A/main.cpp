#include <iostream>

using namespace std;

int T, t, n;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&t,&n);
        if(t==1){
            printf("%d\n", n);
        } else if(t==2){
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
    return 0;
}
