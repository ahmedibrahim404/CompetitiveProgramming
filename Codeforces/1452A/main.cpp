#include <iostream>

using namespace std;

int t, x, y;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&x,&y);
        printf("%d\n", 2 * max(x, y) - 1 + (x == y));
    }
    return 0;
}
