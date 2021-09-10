#include <iostream>

using namespace std;

// x%2 == 1 ? FIRST
// x%2 == 0 ? x%4 == 0 && (x/4)%2 == 1 ? FIRST

int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        long long n;
        scanf("%lld",&n);int c=0;
        while(n%2==0){
            c++;
            n/=2;
        }
        if(c&1) printf("Second Box\n");
        else printf("First Box\n");
    }

    return 0;
}
