#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t;ll n , m;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        ll ns[n+5];
        vector<ll> as, bs;
        bs.push_back(0);
        as.push_back(0);
        for(int i=0;i<n;i++){
            cin >> ns[i];
        }
        for(int i=0;i<n;i++){
            ll no;
            cin >> no;
            if(no==1) as.push_back(ns[i]);
            else bs.push_back(ns[i]);
        }

        sort(as.begin()+1, as.end(), greater<ll>());
        sort(bs.begin()+1, bs.end(), greater<ll>());

        for(int i=1;i<as.size();i++){
            as[i] += as[i-1];
        }

        for(int i=1;i<bs.size();i++){
            bs[i] += bs[i-1];
        }
        int mi=1e9;
//        for(int i=0;i<as.size();i++){
//
//            ll cur=as[i];
//            int took=(i+1);
//            ll need=m-cur;
//
//            if(need > 0){
//                int idx=lower_bound(bs.begin(), bs.end(), need)-bs.begin();
//                if(idx==bs.size()) continue;
//                took += 2*(idx+1);
//            }
//
//            mi=min(mi, took);
//
//        }

        for(int i=0;i<bs.size();i++){

            ll cur=bs[i];
            int took=2*(i);
            ll need=m-cur;


            if(need > 0){
                int idx=lower_bound(as.begin(), as.end(), need)-as.begin();
                if(idx==as.size()) continue;

                took += idx;


            }

            mi=min(mi, took);

        }
        if(mi==1e9) mi=-1;
        cout << mi << "\n";

    }
    return 0;
}
