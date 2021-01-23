#include <iostream>

using namespace std;
typedef long long ll;
ll a, b,n,no;
int main(){
    scanf("%lld%lld%lld",&a,&b,&n);
    while(n--){
        scanf("%lld",&no);
        if(no>1000){
            printf("%lld %lld\n", no, (no-1000)*b+a*1000);
        } else {
                printf("%lld %lld\n", no, no*a);
        }
    }
    return 0;
}
