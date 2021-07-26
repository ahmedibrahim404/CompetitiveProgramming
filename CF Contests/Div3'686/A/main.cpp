#include <iostream>

using namespace std;

int t, n;
int main(){

    cin >> t;
    while(t--){
        cin >> n;
        cout << n << " ";
        for(int i=1;i<n;i++) cout << i << " ";
        cout << "\n";
    }

    return 0;
}
