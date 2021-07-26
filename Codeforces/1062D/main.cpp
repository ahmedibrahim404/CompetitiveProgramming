#include <iostream>

using namespace std;
typedef long long ll;
int n;
ll ns[100000+9];

ll sum(int n){

    ll ss=0;
    for(int i=1;i*i<=n;i++){

        if(n % i != 0) continue;

        if(i*i == n){
            ss += 4*(n/i);
        } else {
            if(i != 1) ss += 4*(n/i) + 4*i;
        }

    }

    return ss;

}

int main(){

    scanf("%d", &n);

    for(int i=4;i<=n;i++){
        ns[i] = ns[i-1];
        ns[i] += sum(i);
    }

    printf("%lld", ns[n]);

    return 0;
}
