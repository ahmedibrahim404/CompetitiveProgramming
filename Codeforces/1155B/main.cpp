#include <iostream>

using namespace std;

int n;
string s;

int main(){
    cin >> n >> s;

    s=s.substr(1, s.length()-2);

    int c=0;
    while(s.length() > 11){
        if(c%2) s=s.substr(1, s.length()-1);
        else {
            int i=0;
            while(s[i] == '8') i++;
            s=s.substr(1, s.length()-1);
        }
        c++;
    }


    if(s.length() >= 11 && c%2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
