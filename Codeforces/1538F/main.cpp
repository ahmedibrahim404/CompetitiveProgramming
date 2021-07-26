#include <iostream>

using namespace std;



int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        int l, r;
        scanf("%d%d",&l,&r);
        int i=1; long long add=0;;
        while(l/i || r/i){

            add += 1LL*(r/i - l/i);
            i *= 10;

        }

        printf("%lld\n", add);

    }
    return 0;
}
