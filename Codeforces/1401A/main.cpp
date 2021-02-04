#include <iostream>

using namespace std;
int t, n, k;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        if(k > n){
            printf("%d\n", abs(n-k));
            continue;
        }
        if((n+k)%2==0) printf("0\n");
        else printf("1\n");
    }
    return 0;
}
