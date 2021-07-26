#include <iostream>

using namespace std;

int q;
long long n,c;
int main(){
    scanf("%d", &q);
    while(q--){
            c=0;
        scanf("%lld", &n);
        while(n%5==0){
            n=(4*n)/5;
            c++;
        }
        while(n%3==0){
            n=(2*n)/3;
            c++;
        }

        while(n%2==0){
            n=(n)/2;
            c++;
        }

        if(n == 1){
            printf("%lld\n", c);
        } else printf("-1\n");

    }

    return 0;
}
