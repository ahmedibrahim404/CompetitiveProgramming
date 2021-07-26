#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6;
const ll MOD=1e9+7;
vector<int> ps(MAX+3, 1);
string s;
int l, r;
int main(){
    ps[0]=0, ps[1]=0;
    for(ll i=2;i<=MAX;i++){
        for(ll j=i*i;j<=MAX;j+=i){
            ps[j]=0;
        }
    }
    for(int i=2;i<=MAX;i++){
        ps[i] += ps[i-1];
    }


    cin >> s;
    cin >> l >> r;

    reverse(s.begin(), s.end());

    int len=s.length(), qs=0;
    for(int i=0;i<len;i++) qs += (s[i]=='?');
    if(s[0] == '?') s[0]='5', qs--;
    if(len >= 2 && s[1]=='?') s[1]='0', qs--;

    if(len == 1){
        if(s[0] == '5'){
            if(r > 1) r=1;
        }
    }


    ll cnt=1;
    if(s[0]=='5' && len > 1 && s[1]=='0'){
        for(int i=0;i<qs;i++){
            cnt *= 10;
            cnt = cnt%MOD;
        }
    }

    if(r > cnt) r=cnt;

    if(l > r) cout << 0 << endl;
    else cout << ps[r]-ps[l-1] << endl;


    return 0;
}
