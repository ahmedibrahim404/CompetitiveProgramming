#include <iostream>

using namespace std;

int a, b, c, d;
int main(){
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(a==d){

        if(c == 0)
            printf("1");
        else if(a > 0 && c > 0)
            printf("1");
        else
            printf("0");
    }
    else
        printf("0");
    return 0;
}
