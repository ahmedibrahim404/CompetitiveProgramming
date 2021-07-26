#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
	cin >> n;
	ll ns[n];
    vector<ll> ans;
    map<ll, set<int>> idx;
    for(int i=0;i<n;i++){
        cin >> ns[i];
    }
    for(int i=0;i<n;i++){
        idx[ns[i]].insert(i);
    }
    auto it = idx.begin();
    for (; it != idx.end();){
        int sz = it->second.size();
        if (sz > 1){
            auto it1=it->second.begin();
            ll left=*it1;
            it->second.erase(it1);
            it1=it->second.begin();
            ll right=*it1;
            it->second.erase(it1);
            ns[left] = -1;
            ns[right] =  ns[right]  * 2 * 1ll;
            ll val = ns[right];
            idx[val].insert(right);
            continue;
        }
        it++;
    }
    for (int i = 0; i < n; i++){
        if (ns[i] != -1){
            ans.push_back(ns[i]);
        }
    }
    cout <<(int) ans.size() << endl;
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
