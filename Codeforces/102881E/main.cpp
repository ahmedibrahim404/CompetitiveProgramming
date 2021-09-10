#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, a[N];
vector<int> ans;
set<int> g[35], st;
void dfs(int u) {
    if(!st.count(u))
        return;
    for(int i = 0;i < 32;i++) {
        if(((1 << i) & a[u]) && g[i].count(u))
            g[i].erase(u);
    }


    st.erase(u);
    ans.push_back(a[u]);
	if(ans.size() == n) {
        for(auto &i : ans)
            cout << i << " ";
        exit(0);
    }


	while(1){
	int mn = 1e9;
	for(int i = 0;i < 32;i++) {
		if((1 << i) & a[u])
			if(g[i].size())
				mn = min(mn, *g[i].begin());
	}
		if(mn != 1e9) dfs(mn);
		else break;
	}

	for(auto i: st){
		dfs(i);
	}

}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("sorting.in", "r", stdin);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        st.insert(i);
        for(int j = 0;j < 30;j++)
            if((1 << j) & a[i])
                g[j].insert(i);
    }
    dfs(1);
    for(auto &i : ans)
        cout << i << " ";
    return 0;
}
