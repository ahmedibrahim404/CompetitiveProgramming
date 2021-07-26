#include <iostream>

using namespace std;

int t, n;


int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int i=2;
        while(true){
            if(n%((1<<i)-1)==0){
                cout << n/((1<<i)-1) << "\n";
                break;
            }
            i++;
        }
    }
    return 0;
}
