#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=100000;
ll fact[MAX];

int n, k;
ll S;
ll no;
vector<ll> n1;
unordered_map<ll, ll> mp[25+1];

void solve(int idx=0, ll sum=0, int tot=0){
    if(sum > S) return;
    if(idx==n/2) {
        mp[tot][sum]++;
        return;
    }
    if(n1[idx]<=18){
        solve(idx+1, sum+fact[ n1[idx] ], tot+1);
    }
    solve(idx+1, sum+n1[idx], tot);
    solve(idx+1, sum, tot);
}
ll ans=0;

void solve2(int idx=n/2, ll sum=0, int tot=0){
    if(sum > S) return;
    if(idx==n) {
        for(int i=0;i<=k-tot;i++){
            if(mp[i].find(S-sum)!=mp[i].end()) ans += mp[i][S-sum];
        }
		return;
	}

    if(n1[idx]<=18){
        solve2(idx+1, sum+fact[ n1[idx] ], tot+1);
    }
    solve2(idx+1, sum+n1[idx], tot);
    solve2(idx+1, sum, tot);
}

int main(){
    fact[1]=1;
    for(int i=2;i<=18;i++){
        fact[i]=fact[i-1]*i;
    }
    scanf("%d%d%lld",&n,&k,&S);
    for(int i=0;i<n;i++){
        scanf("%lld",&no);
        n1.push_back(no);
    }


    solve();
    solve2();

    printf("%lld\n", ans);


    return 0;
}
