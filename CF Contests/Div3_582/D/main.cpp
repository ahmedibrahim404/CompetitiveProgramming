#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX=2e5+3;
ll cnt[MAX], tobe[MAX], ns[MAX];
int n, k;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&ns[i]);
    }
    sort(ns, ns+n);
    ll mi=1e17;
    for(int i=0;i<n;i++){
        ll no=ns[i], cc=0;
        while(no>=0){
            cnt[no]++;
            tobe[no]+=cc;
            if(cnt[no]==k){
                if(tobe[no] <mi){
                    mi=tobe[no];
                }
            }
            cc++;
            if(no==0)break;
            no/=2;
        }
    }

    printf("%lld\n", mi);

    return 0;
}
