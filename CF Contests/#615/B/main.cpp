#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int>pi;
int t, a, b;

//bool cpr(pi sec, pi fir){
//    if(sec.second>fir.second) return 1;
//    if(sec.second==fir.second){
//        if(sec.first>fir.first) return 1;
//        return 0;
//    }
//    return 0;
//}
int n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        vector<pi> ns=vector<pi>(n);
        for(int i=0;i<n;i++){
            cin >> a >> b;
            ns[i]=pi(a, b);
        }
        sort(ns.begin(), ns.end());
        int x=0, y=0;
        bool can=1;
        string ans="";
        for(int i=0;i<n;i++){
            int nx=ns[i].first, ny=ns[i].second;
            if(x>nx || y > ny){
                can=0;
                break;
            }
            for(int j=0;j<nx-x;j++) ans += "R";
            for(int j=0;j<ny-y;j++) ans += "U";
            x=nx, y=ny;
        }

        if(!can) cout << "NO" << endl;
        else cout << "YES\n" << ans << endl;
    }
    return 0;
}
