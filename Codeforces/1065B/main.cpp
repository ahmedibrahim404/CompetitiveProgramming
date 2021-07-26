#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
ll n, m;

ll cal(int num){
    return (ll) (num*(num-1))/2;
}

int main(){

    scanf("%d %lld", &n, &m);
    if(n > (ll) 2*m) printf("%d ", (n-2*m));
    else printf("0 ");
    int start=0, end=n;
    int use=n;
    ll q;
	for(q=0;q<=n;q++){
		if(q*(q-1)/2>=m) break;
	}
    printf("%d", n-q);

    return 0;
}
