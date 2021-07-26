#include <iostream>

using namespace std;

int t, a, b;;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        if(a>b) swap(a, b);

        if(b>2*a){
            printf("%d\n", b*b);
            continue;
        }

        int mi=min(a+b, min(b+b, a+a));
        printf("%d\n", mi*mi);
    }
    return 0;
}
