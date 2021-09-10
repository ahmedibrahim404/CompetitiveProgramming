#include <iostream>

using namespace std;

string s;;

int main(){
    cin >> s;
    int n=s.length();

    bool cc=1;
    for(int i=0;i<n;i++){
        if(s[i] == s[n-i-1]) continue;

        string ns="";for(int j=0;j<n;j++) if(j != i) ns += s[j];bool can=1;
        for(int j=0;j<(n-1)/2;j++) if(ns[j] != ns[(n-1)-j-1]) can=0;
        if(can) return cout << "YES\n" << i+1 << "\n", 0;

        ns="";for(int j=0;j<n;j++) if(j != n-i-1) ns += s[j];can=1;
        for(int j=0;j<(n-1)/2;j++) if(ns[j] != ns[(n-1)-j-1]) can=0;
        if(can) return cout << "YES\n" << n-i << "\n", 0;

        cc=0;
        break;
    }

    if(!cc)cout << "NO\n";
    else cout << "YES\n" << n/2 +1 << "\n";
    return 0;
}
