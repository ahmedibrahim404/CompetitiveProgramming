#include <iostream>

using namespace std;

int main(){
    int n, s;
    scanf("%d%d",&n,&s);

    if(s >= 2*n){
        printf("YES\n");
        s -= (n-1)*2;
        for(int i=0;i<n-1;i++ ) printf("2 ");
        printf("%d\n", s);
        printf("1\n");

    } else printf("NO\n");

    return 0;
}
