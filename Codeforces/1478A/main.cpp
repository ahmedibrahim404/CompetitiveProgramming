#include<bits/stdc++.h>

using namespace std;
int t, n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int ns[100+5];
        memset(ns, 0, sizeof ns);
        int no;
        for(int i=0;i<n;i++){
            cin >> no;
            ns[no]++;
        }
        int mx=0;
        for(int i=1;i<=n;i++){
            mx=max(mx, ns[i]);
        }
        cout << mx << "\n";
    }
    return 0;
}
