#include <iostream>

using namespace std;
typedef long long ll;
int T, n;
ll total=0, sum;
ll ns[500+9][500+9], to[500+9];
int main(){
    scanf("%d", &T);
    while(T--){
        total=0;
        sum=0;
        scanf("%d", &n);

        for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%lld", &ns[i][j]);
        for(int i=0;i<n;i++) scanf("%lld", &to[i]);

        bool taken[500+9];
        for(int i=0;i<n;i++) taken[i]=false;
        for(int k=n-1;k>=0;k--){
            ll cur=to[k];
            taken[cur]=1;
            for(int i=0;i<n;i++) for(int j=0;j<n;j++){
                ns[i][j]=min(ns[i][cur]+ns[cur][j], ns[i][j]);
                if(taken[i] && taken[j]) total += ns[i][j];
            }
        }

        printf("%lld\n", total);

    }
    return 0;
}
