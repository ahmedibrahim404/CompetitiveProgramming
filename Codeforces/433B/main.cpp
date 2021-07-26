#include <iostream>
#include <algorithm>
using namespace std;

int n, m, l, r, type;
long long a[100000+9], b[100000+9];
int main(){

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
        b[i]=a[i];
    }

    sort(b, b+n);
    for(int i=1;i<n;i++) a[i] = a[i-1]+a[i], b[i] = b[i-1]+b[i];

    scanf("%d", &m);
    for(int i=0;i<m;i++){

        scanf("%d %d %d", &type, &l, &r);
        long long ans;
        r--, l--;
        if(type == 1) ans = a[r]-a[l-1];
        else ans = b[r]-b[l-1];

        printf("%lld\n", ans);

    }


    return 0;
}
