#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;

int main(){
    cin >> t;
    string str;
    while(t--){
        cin >> n;
        cin >> str;
        ll cur[n], cnt[n];for(int i=0;i<n;i++)cur[i]=0;
        for(int i=0;i<n;i++){
            if(str[i]=='*') cur[i]=i, cnt[i]=1ll;
            else cur[i]=cnt[i]=0;
            if(i) cur[i] += cur[i-1], cnt[i] += cnt[i-1];
        }

        ll mn=1e18;
        for(int i=0;i<n;i++){
            ll cnt2=cnt[n-1]-cnt[i];
            ll cost = cur[n-1]-cur[i]-(cnt2)*(i+1)-(cnt2*(cnt2-1))/2 - cur[i] + cnt[i] * i - cnt[i] * (cnt[i]-1)/2;
            if(cost < mn) mn=cost;
        }



        reverse(str.begin(), str.end());

        for(int i=0;i<n;i++)cur[i]=0;
        for(int i=0;i<n;i++){
            if(str[i]=='*') cur[i]=i, cnt[i]=1;
            else cur[i]=cnt[i]=0;
            if(i) cur[i] += cur[i-1], cnt[i] += cnt[i-1];
        }

        for(int i=0;i<n;i++){
            ll cnt2=cnt[n-1]-cnt[i];
            ll cost = cur[n-1]-cur[i]-(cnt2)*(i+1)-(cnt2*(cnt2-1))/2 - cur[i] + cnt[i] * i - cnt[i] * (cnt[i]-1)/2;
            if(cost < mn) mn=cost;
        }

        cout << mn << "\n";

    }
    return 0;
}
