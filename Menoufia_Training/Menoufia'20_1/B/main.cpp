#include <iostream>

using namespace std;

int T, a, b;
int main(){
    cin >> T;
    while(T--){
        cin >> a >> b;
        if((a%2)*(b%2)){
            cout << "Hussain";
        } else cout << "Hasan";
        cout << endl;
    }
    return 0;
}
