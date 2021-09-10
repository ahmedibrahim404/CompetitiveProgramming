#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){

    int n;
    scanf("%d",&n);
    ll ns[n+5];
    for(int i=1;i<=n;i++){
        scanf("%lld",&ns[i]);
    }

    ll mp[3][3];
    memset(mp, 0, sizeof mp);

    int p[n+5], s[n+5];
    int pre=0, sum=0;
    for(int i=0;i<=n;i++) p[i]=s[i]=0;
    for(int i=1;i<=n;i++){
        pre += ns[i]%3 * sum%3;
        pre%=3;
        sum += ns[i]%3;
        sum%=3;
        p[i]=pre;s[i]=sum;
        mp[ p[i]%3 ][ s[i]%3 ]++;
    }

    ll ans=0;
    mp[0][0]++;


    for(int i=0;i<n;++i){
        mp[ p[i]%3 ][ s[i]%3 ]--;


        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                if((x-p[i]-(y-s[i])*s[i])%3==0){
                    if(mp[x][y])ans +=1LL * mp[x][y];
                }
            }
        }


    }


    printf("%lld\n", ans);
    return 0;
}
