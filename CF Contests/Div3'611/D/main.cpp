#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int MAX=200000+5;
int n, m, ns[MAX], len[MAX];
int main(){
    cin >> n >> m;
    vi v;

    int mx=0;
    for(int i=0;i<n;i++){
        cin >> ns[i];
    }

    sort(ns, ns+n);

    cout << ans << endl;
    for(int i=0;i<v.size();i++) cout << v[i] << " ";


    return 0;
}
