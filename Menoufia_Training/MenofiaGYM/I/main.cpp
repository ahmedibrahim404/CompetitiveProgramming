#include<bits/stdc++.h>
using namespace std;

int T, n, k, no;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n, &k);
        map<int, int> mp;
        long long sum=0;
        for(int i=0;i<n;i++){
            scanf("%d",&no);
            mp[ no ]++;
        }
        for(int i=-100;i<=100;i++){
            if(i <= 0 && mp.count(i) && mp[i]){
                int mi=min(mp[i], k);
                k-=mi;
                sum += 1LL*mi*(-1*i);
                sum += 1LL*(mp[i]-mi)*i;
            } else sum +=1LL*mp[i]*i;
        }
        for(int i=0;i<=100 && k;i++){
            if(mp[i] || mp[-i]){
                if(k&1==1) sum -= 2 * i;
                break;
            }
        }

        printf("%lld\n", sum);
    }
    return 0;
}
