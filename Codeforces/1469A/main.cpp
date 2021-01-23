#include <iostream>

using namespace std;

string str;
int t;

int main(){
    cin >> t;
    while(t--){
        cin >> str;
        if(str[0]==')' || str[str.length()-1]=='(' || str.length()%2) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
