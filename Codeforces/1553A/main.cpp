#include <iostream>

using namespace std;

int t, n;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%d\n", (n+1)/10);
    }
    return 0;
}
