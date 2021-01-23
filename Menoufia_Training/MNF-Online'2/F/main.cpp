#include<bits/stdc++.h>
using namespace std;
int ns[21], n;
typedef long long ll;
typedef pair<ll, ll> pi;
vector<pi> vs;
int odd[20+3];

bool cpr(pi p2, pi p1){
    if(p2.first < p1.first) return 1;
    if(p2.first == p1.first){
        ll seco2=p2.second, seco1=p1.second;
        while(seco1){
            if((seco2&1)&&!(seco1&1)) return 1;
            else if(!(seco2&1)&&(seco1&1)) return 0;
            seco2/=2;
            seco1/=2;
        }
    }
    return 0;
}

void solve(int cur, ll sum, bitset<20> ans=0, int o=0){

    if(cur == n){
        if((sum%2==0)&&sum!=0) vs.push_back(pi(sum, ans.to_ullong()));
        return;
    }

    ans[cur]=1;
    solve(cur+1, sum+ns[cur], ans, o+(ns[cur]&1));
    ans[cur]=0;
    solve(cur+1, sum, ans, o);

}

int main(){
    scanf("%d",&n);
//    n=20;
    for(int i=0;i<n;i++) {
        scanf("%d",&ns[i]);
//        ns[i]=i+1;
    }
    for(int i=n-1;i>=0;i--){
        if((ns[i]&1)) odd[i]++;
        odd[i] += odd[i+1];
    }
    sort(ns, ns+n);
    solve(0, 0);
    sort(vs.begin(), vs.end(), cpr);
    int sz=vs.size();
    for(int i=0;i<sz;i++){
        printf("%lld ", vs[i].first);
        int idx=0;
        while(vs[i].second){
            if((vs[i].second&1)) printf("%d ", ns[idx]);
            idx++;
            vs[i].second/=2;
        }
        printf("\n");
    }


    return 0;
}
