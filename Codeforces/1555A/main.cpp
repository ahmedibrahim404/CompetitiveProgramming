#include <iostream>

using namespace std;
typedef long long ll;
int t;
ll a;


int main(){
    scanf("%d",&t);

    while(t--){
        scanf("%lld",&a);
        printf("%lld\n", max(6LL, a+1) / 2 * 5 );
    }
    return 0;
}
