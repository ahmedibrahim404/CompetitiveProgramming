#include <iostream>

using namespace std;
int t, n;
string str;
int main(){
    cin >> t;
    while(t--){
        cin >> n >> str;
        int ctr=0;
        for(int i=n-1;i>=0;i--){
            if(str[i] != ')') break;
            ctr++;
        }
        if(ctr > n-ctr) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
