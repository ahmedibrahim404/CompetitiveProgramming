#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll a[200000+9];

int main(){

    scanf("%d", &n);

    for(int i=0;i<n;i++) scanf("%lld", &a[i]);

    ll mxc=a[n-1], pre=a[n-1];

    for(int i=n-2;i>=0;i--){
        ll mi = min( pre-1, a[i] );
        if(mi > 0) mxc += mi, pre=mi;
        else break;
    }

    cout << mxc <<  endl;

    return 0;
}
