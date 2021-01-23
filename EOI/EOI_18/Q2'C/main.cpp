#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T, Q;
ll N,no;
vector<ll> vs;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lld%d",&N,&Q);
        vs=vector<ll>(1e5);

        int idx=0;
        for(int i=1;i*i<=N;i++){
            if(N%i==0){
                if(i*i==N)vs[idx++]=i;
                else {
                    vs[idx++]=i;
                    vs[idx++]=N/i;
                }
            }
        }

        sort(vs.begin(), vs.begin()+idx);
        ll no;
        while(Q--){
            scanf("%lld",&no);
            if(no>vs[idx-1]){
                printf("%lld\n",no);
                continue;
            }
            int ix=lower_bound(vs.begin(),vs.begin()+idx, no)-vs.begin();
            if(vs[ix]==no) printf("%lld\n",vs[ix]);
            else printf("%lld\n", vs[ix-1]);
        }
    }
    return 0;

}
