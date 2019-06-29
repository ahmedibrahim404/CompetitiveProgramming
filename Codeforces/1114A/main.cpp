#include <iostream>
using namespace std;

int x, y, z, a, b, c;

int main(){

    scanf("%d %d %d %d %d %d", &x, &y, &z, &a, &b, &c);

    if( a >= x ){
        a -= x;
        if( a + b >= y ) {
            b -= (y-a);
            a=0;
            if(a + b + c >= z) printf("YES");
            else  printf("NO");
        } else printf("NO");
    } else printf("NO");

    return 0;
}
