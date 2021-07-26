#include<stdio.h>
using namespace std;
typedef long long ll;
int ns[10], t;
ll a, b;
int main(){
    ns[0]=1, ns[1]=0, ns[2]=0, ns[3]=0, ns[4]=1, ns[5]=0, ns[6]=1, ns[7]=0, ns[8]=2, ns[9]=1;
    scanf("%d",&t);
    while(t--){
    scanf("%lld %lld",&a,&b);
    while(b){
        ll total=0;
        if(!a)total=1;
        else {
            while(a){
                total += ns[a%10];
                a/=10;
            }
        }
        b--;
        a=total;
        if(a==0) break;
    }
    if(b==0)
    printf("%lld\n", a);
    else {
    if((b%2==1))
    printf("1\n");
    else printf("0\n");
    }
    }
    return 0;
}
