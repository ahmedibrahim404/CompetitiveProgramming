#include <iostream>

using namespace std;
int t;
int n;
int main(){
    cin >> t;
    while(t--){
            string str;
        cin >> n >> str;
        bool is[26], can=1;
        for(int i=0;i<26;i++) is[i]=0;
        for(int i=0;i<n;i++){
            if(is[ str[i]-'A' ] == 1){
                can=0;
                break;
            }

            while(i+1 < n && str[i+1] == str[i]){
                i++;
            }

            is[ str[i]-'A' ]=1;
        }
        if(!can) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
