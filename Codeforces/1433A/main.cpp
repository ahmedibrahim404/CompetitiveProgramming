#include <iostream>

using namespace std;
int t, x;
int main(){
    cin >> t;
    while(t--){
        cin >> x;
        int len=0, d=x%10;
        while(x){
            len++;
            x/=10;
        }

        cout <<  (d-1)*(10) + len*(len+1)/2  << "\n";


    }
    return 0;
}
