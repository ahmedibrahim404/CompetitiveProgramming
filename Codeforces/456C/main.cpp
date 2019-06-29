#include <iostream>

using namespace std;

int n, a;
long long ns[100000+9];

int main(){

    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%d", &a);
        ns[a]++;
    }

    for(int i=2;i<=99999+2;i++){
        ns[i] = max(ns[i-1], ns[i-2]+(ns[i]*i));
    }


    printf("%lld", ns[100001]);

    return 0;
}
