#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pi;
const int MAX=500+5;
const ll MOD=998244353;
int n, m, k;
ll ns[MAX][MAX];
ll mxrow[MAX], mxcol[MAX];

int main(){

    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ns[i][j];
        }
    }

    ll a, b=0;
    char c;
    ll ans=0;
    while(k--){
        cin >> c >> a >> b;
        a--;
        if(c=='r'){
            mxrow[a]=max(b, mxrow[a]);
        } else {
            mxcol[a]=max(b, mxcol[a]);
        }
    }

    ll res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            res += (ns[i][j]%MOD)*(max(mxrow[i], mxcol[j])%MOD);
            res %= MOD;
        }
    }

    res += MOD;
    res %= MOD;

    cout << res << "\n";

    return 0;
}
