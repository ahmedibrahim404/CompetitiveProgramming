#include <iostream>

using namespace std;
typedef long long ll;
int t; ll n;

int main(){
    cin >> t;
    while(t--){
        ll K;
        cin >> n >> K;
        ll no;
        ll fin=n;
        for(ll i=0;i<min((ll) 100+9, K)-1;i++){
            ll mx=0, mi=15;
            no=fin;
            while(no){
                mx=max(mx, no%10);
                mi=min(mi, no%10);
                no /= 10;
            }
            fin += mx*mi;
        }
        cout << fin << "\n";
    }
    return 0;
}
