#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int n=s.length();
    for(int i=0;i<n-1;i++){
        if(s[i] != s[i+1]) return cout << 2 << endl, 0;
    }

    cout << -1 << endl;

    return 0;
}
