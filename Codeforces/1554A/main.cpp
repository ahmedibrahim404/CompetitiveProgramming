#include <iostream>

using namespace std;

int n;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ns[n];
        long long mx=0;
        for(int i=0;i<n;i++) {
            scanf("%d",&ns[i]);
            if(i) mx=max(mx, 1LL* ns[i] * ns[i-1]);
        }
        printf("%lld\n", mx);
    }
    return 0;
}
