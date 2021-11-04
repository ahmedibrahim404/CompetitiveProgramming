#include<bits/stdc++.h>

using namespace std;
int ns[2000000+3], ms[2000000+3];
int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;string s;
        for(int i=0;i<n;i++){
            cin >> ns[i];
            ms[i] = ns[i];
        }
        cin >> s;
        sort(ms, ms+n);

        bool is=1;for(int i=0;i<n;i++) is &= (ms[i] == (i+1));
        if(is) {
            cout << "YES\n";
            continue;
        }

        vector<int> bs, rs;
        for(int i=0;i<n;i++){
            if(s[i] == 'B') bs.push_back(ns[i]);
            else rs.push_back(ns[i]);
        }

        sort(bs.begin(), bs.end());
        sort(rs.begin(), rs.end());

        is=1;
        for(int i=0;i<bs.size();i++){
            if(bs[i] < i+1) is=0;
        }

        for(int i=0;i<rs.size();i++){
            if(rs[i] > (int)i+1+(int)bs.size()) is=0;
        }

        if(is) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}
