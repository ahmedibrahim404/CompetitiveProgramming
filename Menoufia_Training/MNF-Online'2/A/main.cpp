#include <iostream>

using namespace std;
typedef long long ll;
ll n, T;
int main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        printf("%lld\n", 1+(n-1)*3);
    }
    return 0;
}
