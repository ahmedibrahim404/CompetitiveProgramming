#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;
int t;
ll cw, cs, s, w;
int main(){
    scanf("%d",&t);
    while(t--){

        scanf("%lld%lld",&a,&b);
        scanf("%lld%lld",&cs,&cw);
        scanf("%lld%lld",&s,&w);


        if(s>w){
            swap(s, w);
            swap(cs, cw);
        }

        ll fin=0;

        for(int i=0;i<=cs;i++){

            if(i*s>a)break;

            ll pa=a, pb=b;
            ll ans=i;
            ll pcw=cw, pcs=cs;
            // a take i from s, as much as can from b
            pa-=i*s;
            pcs-=i;


            ll mi=min(pa/w, pcw);
            pcw-=mi;
            pa-=w*mi;
            ans += mi;

            mi=min(pb/s, pcs);

            pcs-=mi;
            pb-=s*mi;
            ans += mi;

            mi=min(pb/w, pcw);

            pcw-=mi;
            pb-=w*mi;
            ans += mi;

            fin=max(fin, ans);

        }




        printf("%lld\n", fin);

    }
    return 0;
}
