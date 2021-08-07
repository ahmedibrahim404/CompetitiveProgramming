#include <iostream>

using namespace std;

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        int n, k;
        scanf("%d%d",&n, &k);int ns[n];
        for(int i=0;i<n;i++) scanf("%d",&ns[i]);
        long long ans = 1LL * n*(n-1) - 1LL * k * (ns[n-1] | ns[n-2]);

        for(int i=max(0, n-200);i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans, 1LL * (i+1)*(j+1) - 1LL * k * (ns[i] | ns[j]));
            }
        }
        printf("%lld\n", ans);

    }
    return 0;
}
