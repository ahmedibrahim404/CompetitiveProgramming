#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
char str[10];
ll p , c ;
int cs=1;
int main(){

    while( scanf("%lld %lld",&p,&c) ){
        if( p == 0 && c == 0 ) break ;
        deque<ll>Q;

        for(int i = 1 ; i <= p && i <= 1000 ; i++ )Q.push_back(i);
        ll x ;
        printf("Case %d:\n",cs++);
        while(c--) {
            scanf("%s",&str);
            if( str[0] == 'N' ) {
                x = Q.front() ;Q.pop_front();Q.push_back(x);
                printf("%lld\n",x);
            } else {
                scanf("%lld",&x);
                for (deque<ll>::iterator i = Q.begin (); i != Q.end (); ++i) if(*i == x ){ Q.erase(i) ; break ; }
                Q.push_front(x);
            }
        }
    }
    return 0;
}
