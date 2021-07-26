#include <iostream>
#include<math.h>

using namespace std;

int n, k;
int main(){
    scanf("%d %d", &n, &k);

    long long ans=ceil( (double) (2*n)/ k ) + ceil( (double) (5*n)/k) + ceil( (double) (8*n)/k);
    printf("%lld", 1LL*ans );

    return 0;
}
