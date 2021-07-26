#include <iostream>

using namespace std;

typedef long long ll;
ll n;

ll sum(ll no){
    return no*(no+1)/2;
}

int main(){
    while(scanf("%lld",&n) && n>=0){
        if(n==1) printf("2\n");
        else if(n==2) printf("4\n");
        else {
            printf("%lld\n", 1 + sum(n));
        }
    }
    return 0;
}
