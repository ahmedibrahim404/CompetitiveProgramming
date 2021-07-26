#include<bits/stdc++.h>

using namespace std;
int t, n, k;
int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        int ns[n];
        for(int i=0;i<n;i++) cin >> ns[i];
        int cnt[2*k + 15], sum[ 2*k + 15 ];
        memset(sum, 0, sizeof sum);
        memset(cnt, 0, sizeof cnt);

        for(int i=0;i<n/2;i++){
            int mi=min(ns[i], ns[n-i-1]);
            int mx=max(ns[i], ns[n-i-1]);
            cnt[ 1+mi ]++;
            cnt[ k+mx+1 ]--;

            sum[ ns[i] + ns[n-i-1] ]++;

        }

        int ans=2e9;
        for(int i=1;i<=2*k+2;i++){
            cnt[i] += cnt[i-1];
            ans = min(ans, ((n/2)-cnt[i])*2 + (cnt[i]-sum[i]));
        }

        cout << ans << "\n";



    }
    return 0;
}
