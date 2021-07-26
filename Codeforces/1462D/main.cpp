#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ll ns[n];
        for(int i=0;i<n;i++) scanf("%lld",&ns[i]);
        map<ll, int> st;
        st[ ns[0] ]=0;
        for(int i=1;i<n;i++) ns[i] += ns[i-1], st[ns[i]]=i;
        int ans=n-1;
        for(int i=0;i<n-1;i++){
            if(ns[n-1] % ns[i]) continue;
            int cur=-1, to=1;
            while(true){
                if(st.find(ns[i]*to) != st.end()){
                    cur=st[ ns[i]*to ]+1;
                    to++;
                } else {
                    break;
                }
            }
            if(cur==n){
                ans=min(ans, n-(to-1));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
