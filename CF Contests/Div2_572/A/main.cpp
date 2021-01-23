#include <iostream>

using namespace std;

int n, ze=0, on=0;;
string s;
int main(){
    cin >> n >> s;
    for(int i=0;i<n;i++) ze += (s[i]=='0');
    on=n-ze;

    if((n&1)==0){
        if(on==ze){
            cout << 2 << "\n" << s.substr(0, 1) << " " << s.substr(1);
        } else cout << 1 << "\n" << s;
     } else {
        cout << 1 << "\n" << s;
    }

    return 0;
}
