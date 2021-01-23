#include<bits/stdc++.h>

using namespace std;
string str;
int q;
int main(){
    cin >> str;
    int n=str.length();
    set<int> st[26];
    for(int i=0;i<n;i++){
        st[ str[i]-'a' ].insert(i);
    }
    cin >> q;
    while(q--){
        int a, b, c;
        char ch;
        cin >> a;
        if(a==1){
            cin >> b >> ch;
            b--;
            st[ str[b]-'a' ].erase( st[ str[b]-'a' ].find(b) );
            st[ ch-'a' ].insert( b );
            str[b]=ch;
        } else {

            cin >> b >> c;
            b--, c--;
            int ans=0;
            for(int i=0;i<26;i++){
                auto it=st[i].lower_bound(b);
                if(it==st[i].end()) continue;
                if( *it <= c ) ans++;
            }

            cout << ans << "\n";

        }
    }
    return 0;
}
