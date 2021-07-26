#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 30'000 + 3;


struct bit {

    int tree[N];
    void init(){
        memset(tree, 0, sizeof tree);
    }

    ll get(int i){
        ll ret=0;
        for(i++; i ; i -= (i&(-i))){
            ret += tree[i-1];
        }
        return ret;
    }

    void add(int i, ll val){
        for(i++;i < N ;i += (i&(-i))){
            tree[i-1] += val;
        }
    }


} bit;

int n;
int main(){

    int t;

    cin >> t;
    while(t--){
            ll ans=0;
    cin >> n;
    bit.init();
    string str;
    map<string, int> mp;
    for(int i=0;i<n;i++){
        cin >> str;
        mp[str] = i;
    }

    for(int i=0;i<n;i++){
        cin >> str;
        ans +=  (i - bit.get(mp[str]));
        bit.add(mp[str], 1);
    }

    cout << ans << "\n";

    }
    return 0;
}
