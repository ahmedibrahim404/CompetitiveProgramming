#include <iostream>

using namespace std;
typedef long long ll;
int main(){

    int t;
    ll a, b;
    scanf("%d", &t);

    while(t--){
        scanf("%lld %lld", &a, &b);
        ll res=0;
        while(a != 0){

            if(a%b != 0){
                res+=(a%b);
                a -= (a%b);
            } else {
                a /= b;
                res++;
            }

        }
        printf("%lld\n", res);
    }

    return 0;
}
