#include<bits/stdc++.h>
using namespace std;
const int MAX=100000+3;
typedef long long ll;
int t, n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        map<ll, int> mp;
        ll no;
        for(int i=0;i<2*n;i++){
            cin >> no;
            if(mp.find(no)==mp.end()) mp[no]=1;
            else mp[no]++;
        }

        auto it=mp.begin();bool can=1;
        vector<ll> vi;
        for(it=mp.begin();it!=mp.end();it++){
            ll fir=it->first;int sec=it->second;
            if(sec%2){
                can=0;
                break;
            } else {
                int cnt=sec/2;
                for(int i=0;i<cnt;i++) vi.push_back(fir);
            }
        }
        if(!can){
            cout << "NO\n";
            continue;
        }
        int sz=vi.size();
        sort(vi.begin(), vi.end(), greater<ll>());
        ll prev=0;
        can=1;
        set<ll>st;
        for(int i=0;i<sz;i++){
            ll tobe=vi[i]-2*prev;
            if(tobe%(2*(n-i))){
                can=0;
                break;
            }
            ll nw=tobe/(2*(n-i));
            if(nw <= 0){
                can=0;
                break;
            }
            if(st.find(nw)==st.end()) st.insert(nw);
            else {
                can=0;
                break;
            }
            prev += nw;
        }

        if(can) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}
