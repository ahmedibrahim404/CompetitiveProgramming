#include <iostream>

using namespace std;


int main(){
    int n;cin >> n;
    string s;cin >> s;

    int sum=0;
    for(int i=0;i<n;i++){
        if(s[i] == '1') {
            if(sum == 1) cout << 0;
            else cout << 1, sum++;
        } else {
            if(sum == 1) cout << 1, sum++;
            else cout << 0;
        }

        if(sum ==2) sum = 1;

    }
    cout << "\n";

    return 0;
}
