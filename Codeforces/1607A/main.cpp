#include <iostream>

using namespace std;

int main(){
    int t;cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        int ns[26] = {0};
        for(int i=0;i<a.size();i++){
            ns[ a[i] - 'a' ] = i;
        }

        int ans=0;
        for(int j=1;j<b.size();j++){
            ans += abs(ns[ b[j]-'a' ] - ns[ b[j-1]-'a' ]);
        }

        cout << ans << endl;

    }
    return 0;
}
