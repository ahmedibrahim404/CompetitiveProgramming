#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, es[100000+3], os[100000+3];
ll ans;
int main(){
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<100000+3;i++) es[i]=os[i]=0;
        ans=1;
        scanf("%d",&n);
        int o=0, e=0, no;
        bool zero=0;
        for(int i=0;i<n;i++){
            scanf("%d",&no);
            if(no>0) es[e++]=no;
            else if(no<0) os[o++]=no;
            else zero=1;
        }


            sort(es, es+e, greater<int>());
            sort(os, os+o);


        int io=0, ie=0;
        for(int i=0;i<2;i++){
            if(ie<e-1&&io<o-1&&ie!=e-2){

                if( es[ie]*es[ie+1] > os[io]*os[io+1] ){
                    ans *= es[ie]*es[ie+1];
                    ie+=2;
                } else {
                    ans *= os[io]*os[io+1];

                    io+=2;
                }


            } else {
                if(ie<e-1){
                    if(ie!=e-2){
                        ans *= es[ie]*es[ie+1];
                    ie+=2;
                    } else {
                        if(io<o-1){
                    ans *= os[io]*os[io+1];
                    io+=2;

                        } else {
                                                ans *= es[ie]*es[ie+1];
                    ie+=2;

                        }
                    }
                } else {
                    ans *= os[io]*os[io+1];
                    io+=2;
                }
            }


        }

        if(ie < e) {
            ans *= es[ie];
        }
        else {
            ans *= os[io];
        }

        if(ans < 0 && zero) ans=0;

        cout << ans << endl;

    }
    return 0;
}
