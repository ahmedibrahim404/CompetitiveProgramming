#include <iostream>

using namespace std;

typedef long long ll;
const int N=10000+3;
ll arr[N];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n, q;
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++) arr[i]=0LL;
        while(q--){
            int a, b;ll c;
            scanf("%d%d%lld",&a,&b,&c);
            arr[a] += c;arr[b+1]-=c;
        }
        for(int i=1;i<n;i++) arr[i] += arr[i-1];
        scanf("%d",&q);
        while(q--){
            int a;
            scanf("%d",&a);
            printf("%lld\n", arr[a]);
        }
    }

    return 0;
}
