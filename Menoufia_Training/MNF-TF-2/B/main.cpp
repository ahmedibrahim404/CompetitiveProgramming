#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int T;
ll N, M;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&N,&M);
        if(N>M) swap(N, M);
        ll gc=__gcd(N, M);
        printf("%lld\n", (N*M)/(gc*gc));
    }
    return 0;
}
