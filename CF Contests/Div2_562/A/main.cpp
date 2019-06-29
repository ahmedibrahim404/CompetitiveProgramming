#include <iostream>

using namespace std;

int n, a, x, b, y;
int main(){
    scanf("%d %d %d %d %d", &n, &a, &x, &b, &y);

    int a1=a, a2=b;
    while(a1++ && a2--){

        if(a1 > n) a1=1;
        if(a2 < 1) a2=n;

        if(a1 == a2){
            return printf("YES\n"), 0;
        }

        if(a1 == x || a2 == y){
            break;
        }


    }

    printf("NO\n");

    return 0;
}
