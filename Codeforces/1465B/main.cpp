#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n;
long long lcm(int a, int b)
{
    return (a / __gcd(a, b)) * b;
}

bool dv(ll x){
    ll pre=x;
    while(pre){
        ll no=pre%10;
        if(no && x%no) return 0;
        pre/=10;
    }
    return 1;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);

        while(!dv(n)){
            n++;
        }

        printf("%lld\n", n);
    }
    return 0;
}
