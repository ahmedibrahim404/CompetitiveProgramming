#include<bits/stdc++.h>
using namespace std;

int T, n, ns[100000+9], no;
map<int, int> mp;
int main(){
    cin >> T;
    while(T--){
        cin >> n;
        int mx=0;
        mp.clear();
        for(int i=0;i<n;i++) cin >> ns[i];
        for(int i=0;i<n;i++) {
            cin >> no;
            if(++mp[ (no-ns[i]) ]>mx)mx=mp[ (no-ns[i]) ];
        }
        cout << mx << endl;
    }
    return 0;
}
