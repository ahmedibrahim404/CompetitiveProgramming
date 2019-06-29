#include <iostream>

using namespace std;
typedef long long ll;

int t;
ll n, k, d1, d2;
int main(){

    scanf("%d", &t);

    while(t--){

        scanf("%lld %lld %lld %lld", &n, &k, &d1, &d2);
        ll rest=n-k;
//        cout << x1 << " " << x2 << " " << x3 << endl;

        ll x1=d1, x2=d2;
//        ll mx=max(x1, max(x2, x3));
//        ll mi=min(x1, min(x2, x3));
        ll rem;

        while((x1 || x2) && rem){

            if(x1){
                rem=min(rest, x1);
                x1-=rem;
                x2+=rem;
                rest -= rem;
            }

            if(x2){
                rem=min(rest, x2);
                x2-=rem;
                rest -= rem;
            }

        }

//        while(rest > 0){
//            bool took=false;
//            ll mx=max(x1, max(x2, x3));
//            ll add;
//            if(mx-x1){
//                add=min(mx-x1, rest);
//                x1+=add;
//                rest-=add;
//                took=true;
//            }
//
//            if(mx-x2){
//                add=min(mx-x2, rest);
//                x2+=add;
//                rest-=add;
//                took=true;
//            }
//
//
//            if(mx-x3){
//                add=min(mx-x3, rest);
//                x3+=add;
//                rest-=add;
//                took=true;
//            }
//
//            if(!took) break;
//
//        }

        if(x1 == x2 && x1 == 0) printf("yes\n");
        else printf("no\n");

    }

    return 0;
}
