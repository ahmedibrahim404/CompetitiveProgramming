#include<bits/stdc++.h>

using namespace std;
int t, n;
int main(){
    cin >> t;
    while(t--){
        int ns[3];
        for(int i=0;i<3;i++) cin >> ns[i];
        sort(ns, ns+3);
        if(ns[1]==ns[2] && ns[1] >= ns[0]){
            cout << "YES\n" << ns[2] << " " << ns[0] << " " << ns[0] << "\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
