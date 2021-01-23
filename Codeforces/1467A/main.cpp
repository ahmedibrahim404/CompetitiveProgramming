#include <iostream>

using namespace std;
int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);

        if(n <= 3){

            if(n==1) printf("9\n");
            else if(n==2) printf("98\n");
            else if(n==3) printf("989\n");

            continue;

        }

        int fir=0;
        n-=3;
        printf("989");
        while(n--){
            printf("%d", fir);
            fir=(fir+1)%10;
        }
        printf("\n");
    }
    return 0;
}
