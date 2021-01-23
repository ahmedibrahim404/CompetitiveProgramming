#include <iostream>

using namespace std;
int t,x,y,n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&x,&y,&n);
        int mod=n%x;
        if(y<mod){
            printf("%d\n", n-(mod-y));
        } else if(y>mod) {
            printf("%d\n", n+(y-mod)-x);
        } else printf("%d\n", n);
    }
    return 0;
}
