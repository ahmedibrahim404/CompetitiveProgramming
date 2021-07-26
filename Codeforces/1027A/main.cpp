#include <iostream>

using namespace std;

int T, n;
string s;

int main(){
    cin >> T;

    while(T--){

        cin >> n >> s;
        bool er=false;
        for(int i=0;i<n/2;i++){

            if(s[i] == s[n-i-1] || abs((s[i]-'a') - (s[n-i-1]-'a')) == 2) continue;
            else {
                er=true;
                break;
            }

        }

        if(er) cout << "NO" << endl;
        else cout << "YES" << endl;

    }

    return 0;
}
