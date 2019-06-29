#include <iostream>

using namespace std;

typedef long long ll;

int n;
int as[200000+9];

int main(){

    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &as[i]);

    ll mi=as[n-1];
    for(int i=n-1;i>=0;i--) if(as[i] < mi) mi=as[i];


    ll ans=(ll) n*mi;
    int cs=0, mx=0;
    for(int i=0;i<2*n;i++){

        if(as[i%n] == mi){
            mx=max(mx, cs);
            cs=0;
        } else {
            cs++;
        }

    }

    printf("%lld", ans+(ll) mx);


    return 0;
}
