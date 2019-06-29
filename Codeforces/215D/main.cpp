#include <iostream>
#include<math.h>
using namespace std;
typedef long long ll;
ll n, m, t, T, x, cost;
int main(){
    scanf("%lld %lld", &n, &m);
    long long total=0;
    while(n--){
        scanf("%lld %lld %lld %lld", &t, &T, &x, &cost);

        if(t+m <= T) total += cost;
        else if( t >= T ) total += cost + m*x;
        else {
            int each=ceil( (double) m/(T-t) );
            if( each*cost > cost + m*x ){
                total += cost + m*x;
//                cout << "ADDED 1 " << cost + m*x << endl;
            } else {
                total += each*cost;
//                cout << "ADDED 2 " << each * cost << endl;
            }
//            total += min( each*cost, cost + m*x );
        }

    }

    printf("%lld", total);
    return 0;
}
