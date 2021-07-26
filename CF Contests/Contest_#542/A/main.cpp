#include <iostream>
#include <math.h>
using namespace std;

int n, a, pos, neg;
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a);
        if(a > 0)
            pos++;
        else if(a < 0)
            neg++;
    }

    if(pos >= ceil((double) n/2)){
        printf("1");
        return 0;
    }

    if(neg >= ceil((double) n/2)){
        printf("-1");
        return 0;
    }

    printf("0");


    return 0;
}
