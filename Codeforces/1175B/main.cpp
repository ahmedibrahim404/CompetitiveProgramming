#include <iostream>

using namespace std;
typedef long long ll;
int l;
ll ans=0;
char str[25];
int last[100000+9];
int main(){

    scanf("%d", &l);

    int a=0, in;
    ll cur=1;
    while(l--){

        scanf("%s", str);
        if(str[0] == 'a'){
            ans += cur;
            if(ans >= 4294967296) return printf("OVERFLOW!!!\n"), 0;
        }
        else if(str[0] == 'f'){
            scanf("%d", &in);
            if(cur >= 1e16){
                ++a;
                continue;
            }
            cur*=in;
            last[++a]=in;
        } else {
            if(last[a] != 0) cur /= last[a];
            last[a]=0;
            a--;
        }

    }

    if(ans >= 4294967296) return printf("OVERFLOW!!!\n"), 0;

    printf("%lld\n", ans);

    return 0;
}
