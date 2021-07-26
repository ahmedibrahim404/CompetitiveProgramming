#include <iostream>

using namespace std;
typedef long long ll;

ll s, d, t;
int n;
ll l[500+1], r[500+1];

int is(int x){
    for(int i=0;i<n;i++){
        if(x>l[i] && x<r[i]) return i;
    }
    return -1;
}


int main(){
    scanf("%lld%lld%lld",&s,&d,&t);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&l[i],&r[i]);
    }


    ll cur=0;

    for(int i=0;i<n;i++){

        ll curl=l[i], curr=r[i];


        if(d<t){

        // case 1
        ll need=max(0, curl-cur);
        if(curl-curr==1) need++;
        else need+=t;
        cur=cur+d;
        int s=is(cur);
        if(s!=-1) cur=l[s];

        } else {

        // case 2
        ll from=max(cur, curr-d);
        ll need2=cur-from;

        }




    }



    printf("%lld\n", ans);
    return 0;
}
