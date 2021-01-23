#include <iostream>

using namespace std;

int t, n;
string str;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        cin >> str;
        string ans;
        for(int i=0;i<n;i++){
            string s=str.substr(i, n);
            ans+=s[i];
        }
        cout << ans <<"\n";
    }
    return 0;
}
