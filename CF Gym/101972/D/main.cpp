#include <iostream>

using namespace std;

int t, n, x, y;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&x,&y);
        int f = n/2 + n%2;
        int s = n/2;
        if(x >= f && y >= s) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
