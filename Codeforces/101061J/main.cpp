#include <iostream>

using namespace std;
typedef long long ll;
int t, n, m;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);ll ns[n];ll arr[n+1]={0};
        for(int i=0;i<n;i++) scanf("%lld",&ns[i]);
        while(m--){
            int a;ll b;
            scanf("%d%lld",&a,&b);
            a--;
            arr[a]+=b;
        }

        for(int i=0;i<n;i++){
            if(arr[i] > ns[i]) arr[i+1] += arr[i] - ns[i], arr[i] = ns[i];
        }
        printf("%lld\n", arr[n]);
        for(int i=0;i<n;i++){
            if(i != n-1)printf("%lld ", arr[i]);
            else printf("%lld\n", arr[i]);
        }

    }
    return 0;
}
