#include <iostream>

using namespace std;

int t, n;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ns[2][n+5] = {0};

        for(int j=0;j<2;j++)
        for(int i=0;i<n;i++) scanf("%d",&ns[j][i]);

        for(int i=n-2;i>=0;i--){
            ns[0][i] += ns[0][i+1];
        }

        for(int i=1;i<n;i++){
            ns[1][i] += ns[1][i-1];
        }

        int ans=2e9;
        for(int i=0;i<n;i++){
            ans = min(ans, max(i+1 < n ? ns[0][i+1] : 0, i ? ns[1][i-1] : 0));
        }

        printf("%d\n", ans);

    }
    return 0;
}
