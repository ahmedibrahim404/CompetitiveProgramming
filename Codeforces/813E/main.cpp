#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll n,k,q,l,r,lst,arr[100005],pre[100005];

vector<vector<ll>>seg(400005);
map<ll,vector<ll>>mp;

void build(ll node,ll s,ll e){
	if(s == e){
		seg[node].push_back(pre[s]);
		return;
	}
	ll mid = s + (e - s)/2;
	build(node * 2 + 1,s,mid);
	build(node * 2 + 2,mid + 1,e);

    merge( seg[2*node+1].begin(), seg[2*node+1].end(), seg[2*node+2].begin(), seg[2*node+2].end(), inserter(seg[node], seg[node].begin()));

}

ll query(ll node,ll s,ll e,ll l,ll r,ll val){
	if(s > r || e < l)
		return 0;
	if(s >= l && e <= r)
		return (lower_bound(seg[node].begin(),seg[node].end(),val) - seg[node].begin());
	ll mid = s + (e - s)/2;
	return query(node * 2 + 1,s,mid,l,r,val) + query(node * 2 + 2,mid + 1,e,l,r,val);
}


int main(){
	cin >> n >> k;
	for(int i = 0;i<n;i++)
		cin >> arr[i],mp[arr[i]].push_back(i);
	for(auto i:mp)
		for(int j = 0;j<i.second.size();j++)
			(j<k)?pre[i.second[j]] = -1:pre[i.second[j]] = i.second[j - k];

	build(0,0,n-1);
	cin >> q;

	while(q--){
		cin >> l >> r;
		l = (l + lst)%n;
		r = (r + lst)%n;
		if(l > r)
			swap(l,r);
		lst = query(0,0,n-1,l,r,l);
		cout << lst << '\n';
	}
	return 0;
}
