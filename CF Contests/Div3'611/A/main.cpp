#include <iostream>

using namespace std;
int t, h, m;
int main(){
    cin >> t;
    while(t--){
        cin >> h >> m;
        cout << (23-h)*60+(60-m) << endl;
    }
    return 0;
}
