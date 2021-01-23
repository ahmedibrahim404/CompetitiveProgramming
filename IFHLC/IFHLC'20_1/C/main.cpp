#include <iostream>

using namespace std;
typedef long long ll;
int n, s;
ll t;

int main(){
    scanf("%d",&n);
    while(n--){

        scanf("%lld%d",&t,&s);
        ll pre, no, ans=0;
        scanf("%lld",&pre);
        for(int i=0;i<s-1;i++){
            ll cur=(pre+1)%t;
            if(!cur) cur=t;
            scanf("%lld",&no);
            ans += min( (t-cur)+1+(no-1), min(abs(cur-no),  cur+(t-no)) );
//            cout << "PUSH " << min( (t-cur)+1+(no-1), abs(cur-no) ) << " TIMES " << endl;
            pre=no;
        }

        printf("%lld\n", ans);

    }
    return 0;
}
