#include <iostream>

using namespace std;
int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n&1) n--;
        printf("%d\n", n/2);
    }
    return 0;
}
