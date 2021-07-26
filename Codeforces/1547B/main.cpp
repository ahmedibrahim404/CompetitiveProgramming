#include <iostream>

using namespace std;

int t, n;

int main(){
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n=s.length();
        bool can=1;
        int i=0, j=n-1, c=n-1;
        while(j>=i){


            if(s[i]-'a' == c){
                i++;
                c--;
            } else if(s[j]-'a' == c) {
                j--;
                c--;
            } else {
                can=0;
                break;
            }


        }

        if(can) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}
