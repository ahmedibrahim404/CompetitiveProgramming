#include <iostream>
using namespace std;
typedef long long ll;
ll num;
int main(){

    scanf("%lld",&num);
    // 10 11 12 13


    ll cnt=0;
    for(int i=10;i<=num;i+=10){
        if(num%11==0&&num%12==0&&num%13==0) cnt++;
    }
    printf("%lld", cnt);
    return 0;
}
