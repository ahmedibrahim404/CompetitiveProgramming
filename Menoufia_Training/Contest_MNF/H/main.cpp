#include <iostream>

using namespace std;

int n, k;
int main(){
    scanf("%d %d",&n,&k);
    if(n<=k){
        printf("10\n");
    } else printf("%lld\n", 1LL*((n/k)+(n%k!=0))*5);
    return 0;
}
