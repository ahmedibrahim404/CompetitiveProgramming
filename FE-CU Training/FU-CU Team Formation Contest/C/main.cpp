#include <iostream>

using namespace std;
typedef long long ll;
int n, s;
ll t;

int main(){
    scanf("%d",&n);
    while(n--){

        scanf("%lld%d",&t,&s);
        ll bef, no;
        ll res=0;
        scanf("%lld",&bef);
        for(int i=0;i<s-1;i++){
            ll cur=(bef+1)%t;
            if(!cur) cur=t;
            scanf("%lld",&no);
            res += min( (t-cur)+1+(no-1), min(abs(cur-no),  cur+(t-no)) );
            bef=no;
        }

        printf("%lld\n", res);

    }
    return 0;
}
