#include <iostream>

using namespace std;

int t, n;
string s;

int main(){

    cin >>t;
    while(t--){
        cin >> n >> s;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='8'){
                idx=i;
                break;
            }
        }

        if(idx >= 0 && n-idx >= 11)
            cout << "YES" << endl;
        else cout << "NO" << endl;

    }

    return 0;
}
