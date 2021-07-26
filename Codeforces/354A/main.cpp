#include <iostream>

using namespace std;

int n, l, r, ql, qr, ns[100000+9];

int main(){
    scanf("%d %d %d %d %d", &n, &l, &r, &ql, &qr);

    for(int i=1;i<=n;i++){
        scanf("%d", &ns[i]);
        ns[i] += ns[i-1];
    }

    long long ans=1e17;
    for(int i=0;i<=n;i++){
        long long preans=ns[i]*l + (ns[n]-ns[i])*r;
        if ((n-i) > i) preans += qr*((n-i)-i-1);
        if ((n-i) < i) preans += ql*(i-(n-i)-1);
        if(preans < ans) ans=preans;
    }

    printf("%lld", ans);

    return 0;
}
