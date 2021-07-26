#include <iostream>

using namespace std;
int t,x,y;
int main(){
    cin >> t;
    while(t--){
        cin >> x >> y;
        if(x-y==1) cout << x-1 << " " << x-1 << "\n";
        else cout << x-1 << " " << y << "\n";
    }
    return 0;
}
