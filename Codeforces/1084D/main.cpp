#include<bits/stdc++.h>
#define  ll long long
using namespace std;

const int N=3e5+10;
vector<pair<ll,ll> >v[N];
ll dp[N];
ll ans = 0;
ll n,val[N],x,y,c;

void dfs(ll u ,ll go){
	dp[u] = val[u];
	ans = max(dp[u],ans);
	for(int i = 0 ; i < v[u].size() ; i++){
		ll to = v[u][i].first;
		if(to==go) continue;
		dfs(to,u);
		ans = max(ans,dp[to]+dp[u]-v[u][i].second);
		dp[u] = max(dp[u],val[u]+dp[to]-v[u][i].second);
	}
}

int main(){
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		cin>>val[i];
	}
	for(int i =1 ; i < n ; i++){
		cin>>x>>y>>c;
		v[x].push_back(make_pair(y,c));
		v[y].push_back(make_pair(x,c));
	}
	dfs(1,0);
	cout<<ans<<endl;

}
