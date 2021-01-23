#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pl;
int t, m;
const int MAX=100000+3;
ll n; vector<pl> ns;
ll freq[MAX];

bool cpr(pl sec, pl fir){
    return(sec.first>fir.first);
}

int getidx(ll no){
    int st=0, en=m-1;
    int mid;
    while(en>=st){
        mid=(st+en)>>1;
        if(ns[mid].first>no) st=mid+1;
        else en=mid-1;
    }
    return st-1;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld%d",&n,&m);
        ns=vector<pl>(m);
        for(int i=0;i<m;i++){
            scanf("%lld%lld",&ns[i].first,&ns[i].second);
        }
        sort(ns.begin(), ns.end(), cpr);
        freq[0]=ns[0].first;
        for(int i=1;i<m;i++) freq[i]=freq[i-1]+ns[i].first;
        ll mx=0;
        for(int i=0;i<m;i++){
            ll res=ns[i].first;
            ll fir=ns[i].first, sec=ns[i].second;
            int idx=getidx(sec);
            if(ns[idx].first > sec){
                int take=min((int)n, idx+1);
                res +=freq[take-1]-(fir>sec?fir:0);
                res += 1LL*(n-1-take+(fir>sec))*sec;
            } else {
                res += (n-1)*sec;
            }
            mx=max(mx, res);
        }
        cout << mx << endl;
    }


    return 0;
}
