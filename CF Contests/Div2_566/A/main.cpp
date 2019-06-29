#include <iostream>

using namespace std;
int n;
int main(){
    scanf("%d", &n);
    if(n&1) return printf("0\n"), 0;
    long long res=1;
    for(int i=0;i<(n/2);i++) res = res * 2;
    printf("%lld", res);
    return 0;
}
