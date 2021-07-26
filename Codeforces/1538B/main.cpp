#include <iostream>

using namespace std;
typedef long long ll;
int t, n;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ll tot=0;
        ll ns[n];
        for(int i=0;i<n;i++){
            scanf("%lld",&ns[i]);
            tot += ns[i];
        }

        if(tot % n){
            printf("-1\n");
            continue;
        }

        ll each=tot/n;int c=0;
        for(int i=0;i<n;i++)
            if(ns[i] > each) c++;


        printf("%d\n", c);
    }
    return 0;
}
