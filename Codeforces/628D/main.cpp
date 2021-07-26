#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
int m, d;
string a, b;
int n;
ll dp[2000+3][2000+3][2][2];

ll solve(int idx, int mod, bool prev, bool prev2){

    if(idx==n){
        return (mod==0?1LL:0);
    }
    ll &ret=dp[idx][mod][prev][prev2];
    if(~ret){
        return ret;
    }
    ret=0;

    int st=a[idx]-'0', en=b[idx]-'0';
    if(!prev) en=9;
    if(!prev2) st=0;

    if(idx&1){
        bool p=prev, p2=prev2;
        if(d!=en) p=0;
        if(d!=st) p2=0;
        if(d>=st&& d<=en) ret += solve(idx+1, (mod*10+d)%m, p, p2)%MOD;
        return ret%MOD;
    }


     for(int i=st;i<=en;i++){
        if(i==d) continue;
        bool p=prev, p2=prev2;
        if(i != en) p=0;
        if(i != st) p2=0;
        ret += solve(idx+1, (mod*10+i)%m, p, p2)%MOD;
        ret %= MOD;
    }

    return ret%MOD;


}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin >> m >> d;
    cin >> a >> b;
    n=a.length();
//    for(int i=0;i<n;i+=2){
//        int na=a[i]-'0';
//        if(na==d){
//            if(d==9){
//                cout << "0\n";
//                return 0;
//            }
//            a[i]=(d+1)+'0';
//        }
//    }

//    int cnt=0;
//    int aa=stoi(a), bb=stoi(b);
//    for(int i=aa;i<=bb;i++){
//        bool is=1;
//        if(i%m) is=0;
//        if(!is) continue;
//        int ni=i;
//        int pos=n;
//        while(ni){
//            if(!(pos&1)){
//                if((ni%10)!=d) {is=0;break;}
//            } else {
//                if((ni%10)==d) {is=0;break;}
//            }
//            pos--;
//            ni/=10;
//        }
//        if(is){
//            cout << i << endl;
//            cnt++;
//        }
//
//    }
//
//    cout << cnt << endl;

    cout << solve(0, 0, 1, 1)%MOD << endl;


    return 0;
}
