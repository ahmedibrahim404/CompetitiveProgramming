#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        multiset<ll> st;
        vector<pi> vi;

        for(ll i=1;i<=n;i++) st.insert(i);
        while(st.size() > 1){


            auto it=st.end();
            it--;
            ll val1=*it;
            st.erase(it);

            it=st.end();
            it--;
            ll val2=*it;
            st.erase(it);

            vi.push_back({val1, val2});

            st.insert((val1+val2+1)>>1);

        }

        printf("2\n");
        for(auto pi: vi){
            printf("%lld %lld\n", pi.first, pi.second);
        }




    }
    return 0;
}
