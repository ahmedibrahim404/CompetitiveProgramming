#include <iostream>

using namespace std;
typedef long long ll;
int t, n;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ll a[n], b[n], c[n];
        for(int i=0;i<n;i++) scanf("%lld",&c[i]);
        for(int i=0;i<n;i++) scanf("%lld",&a[i]);
        for(int i=0;i<n;i++) scanf("%lld",&b[i]);

        ll mx=0;
        ll lstLen = 0;
        for (int i = 1; i < n; i++) {
          ll curLen = c[i] + 1ll + abs(a[i] - b[i]);
          if (a[i] != b[i])
            curLen = max(curLen, c[i] + 1ll + lstLen - abs(a[i] - b[i]));
          mx = max(mx, curLen);
          lstLen = curLen;
        }

        cout << mx << "\n";

    }
    return 0;
}
