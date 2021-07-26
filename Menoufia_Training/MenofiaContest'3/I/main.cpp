#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
struct tr {
    int first, second, third;
};
bool cmp(tr t2, tr t1){
    return t2.first > t1.first;
}
int n, k;
vector<pi> tb;
vector<tr> ns;
int main(){
    cin >> n;
    ns=vector<tr>(n);
    for(int i=0;i<n;i++){
        cin >> ns[i].second >> ns[i].first;
        ns[i].third=i+1;
    }
    cin >> k;
    tb=vector<pi>(k);
    for(int i=0;i<k;i++){
        cin >> tb[i].first;
        tb[i].second=i+1;
    }

    sort(ns.begin(), ns.end(), cmp);
    sort(tb.begin(), tb.end());
    int total=0, mx=0;
    vector<pi> ans=vector<pi>(n);
    for(int i=0;i<n;i++){
        int v=ns[i].first, no=ns[i].second;
        int idx=lower_bound(tb.begin(), tb.end(), pi(no, -1e9))-tb.begin();
        if(tb[idx].first >= no){
            total += v;
            ans[mx].first=ns[i].third;
            ans[mx++].second=tb[idx].second;
            tb.erase(tb.begin()+idx);
        }
    }

    cout << mx << " " << total << endl;
    for(int i=0;i<mx;i++) cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}

