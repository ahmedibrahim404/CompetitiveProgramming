#include <iostream>

using namespace std;
int t, n;
string str;
int main(){
    cin >> t;
    while(t--){
        cin >> n >> str;
        string tobe="2020";
        bool can=1;
        for(int i=0;i<4;i++){
            if(str[i] != tobe[i]) can=0;
        }
        if(can){
            cout << "YES\n";
            continue;
        }

        can=1;
        int cur=0;
        for(int i=n-4;i<n;i++){
            if(str[i]!=tobe[cur]) can=0;
            cur++;
        }
        if(can){
            cout << "YES\n";
            continue;
        }

        can=0;
        if(str[0]=='2' && str[n-3]=='0' && str[n-2]=='2' && str[n-1]=='0') can=1;
        if(str[0]=='2' && str[1]=='0' && str[n-2]=='2' && str[n-1]=='0') can=1;
        if(str[0]=='2' && str[1]=='0' && str[2]=='2' && str[n-1]=='0') can=1;
        if(can){
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";

    }
   return 0;
}
