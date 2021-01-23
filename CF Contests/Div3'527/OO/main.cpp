#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll t, no;

int main(){

    scanf("%d%lld",&n,&t);
    int ans=0;
    bool add=0;
    vector<ll> pos, neg;
    for(int i=0;i<n;i++){
        scanf("%lld",&no);
        if(no>0) pos.push_back(no);
        else if(no==0) add=1;
        else neg.push_back(-no);
    }

    reverse(neg.begin(), neg.end());

    int ps = pos.size(), ns=neg.size();
    for(int i=0;i<ps;i++){

        if(t-pos[i]>=0){
            int extra=0;
            if(t-2*pos[i] > 0){
                ll rem=t-2*pos[i];
                int idx=lower_bound(neg.begin(), neg.end(), rem)-neg.begin();
                if(idx==ns){
                    idx--;
                }
                if(idx>=0 &&neg[idx]>rem) idx--;
                if(idx>=0 &&rem>=neg[idx]) extra=idx+1;
            }
            ans=max(ans, (i+1)+extra);
        } else break;
    }

    for(int i=0;i<ns;i++){
        if(t-neg[i]>=0){
            int extra=0;
            if(t-2*neg[i] > 0){
                ll rem=t-2*neg[i];
                int idx=lower_bound(pos.begin(), pos.end(), rem)-pos.begin();
                if(idx==ps){
                    idx--;
                }
                if(idx>=0 &&pos[idx]>rem) idx--;
                if(idx>=0 &&rem>=pos[idx]) extra=idx+1;
            }
            ans=max(ans, (i+1)+extra);
        } else break;
    }

    printf("%d\n", ans+add);

    return 0;
}
