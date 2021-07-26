#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, m, k;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ns[n];
//        set<int> st;
        map<int, int> mp;
        for(int i=0;i<n;i++){
//            int no;
            scanf("%d",&ns[i]);
            mp[ ns[i] ]++;
//            st.insert(no);
        }

//        n=st.size();

        sort(ns, ns+n);

        long long ans=0;
        for(int i=0;i<n;i++){

            int cur=ns[i];

            int idx1=upper_bound(ns, ns+n, ns[i]+1)-ns;
            ll first=1LL*(idx1-i-1);

            int idx2=lower_bound(ns, ns+n, ns[i]-1)-ns;
            ll second=1LL*(i-idx2);

            ans += first*second;

            if(i && cur == ns[i-1]) continue;

            if(mp[cur] > 1 && mp.find(cur + 2) != mp.end()){
                ans += mp[cur]*(mp[cur]-1)/2 * mp[cur+2];
            }


            if(mp[cur] > 1 && mp.find(cur - 2) != mp.end()){
                ans += mp[cur]*(mp[cur]-1)/2 * mp[cur-2];
            }

        }

        printf("%lld\n", ans);

    }
    return 0;
}
