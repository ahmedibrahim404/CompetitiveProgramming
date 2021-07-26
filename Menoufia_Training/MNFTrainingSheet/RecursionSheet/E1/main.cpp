#include <iostream>

using namespace std;
int N;

void p(int n){

    if(n==0) return;
    p(n-1);
    int tot=((2*N-1)-(2*n-1))>>1;
    for(int i=0;i<tot;i++) printf(" ");
    for(int i=0;i<2*n-1;i++) printf("*");
    printf("\n");

}


int main(){
    scanf("%d",&N);
    p(N);
    return 0;
}
