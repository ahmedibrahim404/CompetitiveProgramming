#include <iostream>
#include<math.h>
using namespace std;
typedef long long ll;

int n;
int main(){
    scanf("%d", &n);

    if(n == 1) return printf("1"), 0;

    int a=1;

    long long total=0;
    for(int i=0;i<n;i++){
        total += a;
        a+=2;
    }

    a-=2;
    total *= 2;
    total -= a;

    printf("%lld", total);

    return 0;
}
