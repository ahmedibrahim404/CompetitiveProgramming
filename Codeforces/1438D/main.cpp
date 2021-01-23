#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+3;
int n;
ll ns[MAX];


int main(){

    scanf("%d",&n);
    ll tot=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&ns[i]);
        tot ^= ns[i];
    }

    if(!(n&1) && tot) return printf("NO\n"), 0;
    printf("YES\n%d\n", (n-1)/2 * 2);
    for(int i=0;i<n-2;i+=2){
        ns[i]=ns[i+1]=ns[i+2]=(ns[i]^ns[i+1]^ns[i+2]);
        printf("%d %d %d\n", i+1, i+2, i+3);
    }

    for(int i=0;i<n-2;i+=2){
        printf("%d %d %d\n", i+1, i+2, n);
        ns[i]=ns[i+1]=ns[n-1]=(ns[i]^ns[i+1]^ns[n-1]);
    }

//    for(int i=0;i<n;i++){
//        printf("%d ", ns[i]);
//    }

    return 0;
}
