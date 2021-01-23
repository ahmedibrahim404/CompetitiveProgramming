#include <iostream>

using namespace std;

int n, k;

int main(){
    scanf("%d",&n);
    if(n==1){
        printf("1\n1\n");
        return 0;
    }
    if(n==2){
        printf("2\n1 2\n");
        return 0;
    }
    printf("%d\n", ((n+1)/2)+(n%2==0));
    for(int i=1;i<=n;i+=2){
        printf("%d ", i);
    }
    if(n%2==0)
    printf("%d\n", n);


    return 0;
}
