#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int cnt=0;
ll a, b;
int main(){

    scanf("%lld %lld", &a, &b);

    ll c=0;
    while(b != 0 && a != 0){
        if(a >= b) c+=a/b, a%=b;
        else c+=b/a, b%=a;
    }

    printf("%lld", c);

    return 0;
}
