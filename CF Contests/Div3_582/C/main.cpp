#include <iostream>

using namespace std;
typedef long long ll;
int q;
ll n,m;
int vis[10+3];
ll cy[1000000];
int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%lld%lld",&n,&m);
        for(int i=0;i<10;i++) vis[i]=0;
        int tot=0;
        bool br=0;

        for(ll i=m;i<=n;i+=m){
            if(vis[i%10]==2){
                br=1;
                break;
            }
            cy[tot]=i%10;
            vis[i%10]++;
            tot ++;
        }

        if(br) tot /= 2;
        if(tot==0){
            printf("0\n");
            continue;
        }


        for(int i=1;i<tot;i++){
            cy[i] += cy[i-1];
        }



        ll to=n/m;
        ll rem=(n/m)%tot;


        printf("%lld\n", (to/tot)*cy[tot-1]+cy[rem-1]);

    }
    return 0;
}
