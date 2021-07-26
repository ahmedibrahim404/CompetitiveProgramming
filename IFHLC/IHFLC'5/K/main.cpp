#include <iostream>

using namespace std;
int T, N;
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        int cur=1;
        for(int i=1;i<=N;i++){
            cur *= i;
            cur %= 10;
        }
        cout << cur << endl;
    }
    return 0;
}
