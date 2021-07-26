#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX=200000+3;
int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        map<ll, ll> mp;
        for(int i=0;i<n;i++){
            ll no;
            scanf("%lld",&no);
            if(mp.find(no) == mp.end()) mp[no]=1LL; else mp[no]++;
        }
        vector<ll> ns,ms;
        for (auto it=mp.begin(); it!=mp.end(); ++it)
            ns.push_back(it->second);

        sort(ns.begin(), ns.end());

        int sz=ns.size();int mx=0;
        for(int i=0;i<sz;i++){
            ms.push_back(ns[i]);
            mx=max(mx, (int) ms[i]);
            if(i) ns[i] += ns[i-1];
        }
        ll ans=1e9, mn=0;
        for(int i=0;i<=mx;i++){

            int idx=lower_bound(ms.begin(), ms.end(), i)-ms.begin();

//            cout << i << " " << idx << " " << ns[sz-1] << " " << ns[idx-1] << " " <<  "\n";
//            cout << ns[sz-1] - i * (sz-idx) << "\n";
            if(ans > ns[sz-1] - i * (sz-idx)  ){
                ans =ns[sz-1] - i * (sz-idx) ;
            }
        }

        printf("%lld\n", ans);

    }
    return 0;
}
