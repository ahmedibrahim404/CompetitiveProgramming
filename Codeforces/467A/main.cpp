#include <iostream>

using namespace std;

int n, a, b, cnt=0;
int main(){

    scanf("%d", &n);

    while(n--){
        scanf("%d %d", &a, &b);
        if(b-a >= 2) cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}
