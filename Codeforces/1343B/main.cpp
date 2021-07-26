#include<bits/stdc++.h>

using namespace std;
int t, n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        if(n%4){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vector<int> v1, v2;
        int cur=1;
        while(n){
            v1.push_back(cur);v1.push_back(cur+4);
            v2.push_back(cur+1);v2.push_back(cur+3);
            cur += 6;
            n -= 4;
        }
        for(int no: v2) cout << no << " ";
        for(int no: v1) cout << no << " ";
        cout << "\n";
    }

    return 0;
}
