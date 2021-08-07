#include <iostream>

using namespace std;

int q;
string s, t;

int main(){
    cin >> q;
    while(q--){
        cin >> s >> t;
        int cur=0, n=s.length(), m=t.length();
        if(m > n){
            cout << "NO\n";
            continue;
        }
        for(int i=(n-m)%2;i<n && cur < m;){
            if(s[i] == t[cur]){
                cur++, i--;
            }
            i+=2;
        }
        if(cur == m) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}
