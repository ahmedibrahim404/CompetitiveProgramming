#include <iostream>
#include <math.h>
using namespace std;

typedef long long ll;

ll n, x, y;
int q;

int main(){

    scanf("%lld %d", &n, &q);

    while(q--){

        scanf("%lld %lld", &x, &y);

        ll ans=0;

		if ((x+y)%2==0) {
			if (n%2==0) {
				ans+=(x-1)*(n/2);
				ans+=(y+1)/2;
			} else {
				ans+=((x-1)/2)*n;
				if (x%2==0) ans+=n-n/2;
				ans+=(y+1)/2;
			}
		}
		else {
			if (n%2==0) {
				ans+=n*n/2;
				ans+=(x-1)*(n/2);
				ans+=(y+1)/2;
			}
			else {
				ans+=n*n/2+1;
				ans+=((x-1)/2)*n;
				if (x%2==0) ans+=n/2;
				ans+=(y+1)/2;
			}
		}


        printf("%lld\n", ans);

    }


    return 0;
}
