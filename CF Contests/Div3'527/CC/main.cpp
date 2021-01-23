#include <iostream>

using namespace std;
typedef long long ll;
int T;
ll L, R, S;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld",&L,&R,&S);
        if(S>R) {printf("-1 -1\n");continue;}
        ll st=(L+S-1)/S;
        ll en=R/S;
        if(st>en){
            printf("-1 -1\n");
            continue;
        }
        printf("%lld %lld\n", st, en);
    }
    return 0;
}
