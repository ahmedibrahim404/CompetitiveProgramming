#include <iostream>

using namespace std;



int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int c;
        switch((a-1) % 4) {
          case 0: c = (a-1); break;
          case 1: c = 1; break;
          case 2: c = a; break;
          case 3: c = 0; break;
        }

        if(c == b){
            cout << a << "\n";
            continue;
        }

        int req = b ^ c;

        int ans = a;
        if(req == a) ans += 2;
        else ans ++;

        cout << ans << "\n";

    }
    return 0;
}
