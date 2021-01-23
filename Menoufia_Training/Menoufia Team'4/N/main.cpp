#include <iostream>

using namespace std;
typedef long long ll;

ll ans=1, no;
int n;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%lld",&no);
        ans *= no;
    }
    printf("%lld\n", ans);
    return 0;
}
